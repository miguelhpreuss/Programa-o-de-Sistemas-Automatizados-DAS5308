/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Tela;

import java.awt.*;
import java.awt.event.*;
import Classes.Stock;
import Classes.Product;
import java.util.Arrays;
import java.util.HashSet;

// comentei código que a IDE diz é declarado e nao é usado
public class Screen extends Frame {
    
    private TextField TFaddName;
    private TextField TFaddBrand;
    private TextField TFaddPrice;
    private TextField TFaddQuantity;
    
    private TextField TFbrandConsulting;
    private TextField TFproductConsulting;
    //private TextField TFpriceConsulting;
    
    //private TextField TFproductName;
    //private TextField TFnewPrice;  
    
    private Button BaddProduct;
    //private Button BbrandConsulting;
    private Button BproductConsulting;
    //private Button BremoveProduct;
    //private Button BsaveNewPrice;
    //private Button BbrandsList;
    private Button BproductsList; 
    
    //private TextArea VisualizationArea;

    private Checkbox ListingName;
    private Checkbox ListingPrice;
    
    private List VisualizationField;
    
    Stock stock;
    Product product;
    
    
    // Classe interna para receber eventos associados com a janela
    class WindowListener extends WindowAdapter {
        public void windowClosing(WindowEvent e) {
            System.out.println("A janela foi fechada");
            System.exit(0);
        }
    }
    
    /*  ADICIONAR
        -Verifica há alguma coisa escrita nos campos
        -Se tiver um produto com mesmo nome, atualiza o produto (eu sei que nao precisava atualizar nada)
        -Se não existir outro com mesmo nome, adiciona
    */
    class AddProductListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            
            VisualizationField.clear();
            String name = TFaddName.getText();
            String brand = TFaddBrand.getText();
            String price = TFaddPrice.getText();
            String quantity = TFaddQuantity.getText();
            
            if ((name.length() > 0) && (brand.length() > 0) && (price.length() > 0)){
                boolean exists = false;
                for (Product product : stock.myProducts) {
                    if (product.getName().equals(name) && product.getBrand().equals(brand)){
                        product.setPrice(price);
                        product.setQuantity(quantity.length() == 0 ? "1": quantity);
                        VisualizationField.add("[INFO]: Produto atualizado com sucesso:");
                        VisualizationField.add("Nome: " + product.getName() + " Marca: " + product.getBrand() + " Preço: " + product.getPrice() + " Quantidade: " + product.getQuantity());
                        exists = true;
                        break;
                    }
                }
                if(!exists){
                    Product product;
                    if (quantity.length() > 0){
                        product = new Product(name, brand, price, quantity);
                    }
                    else {
                        product = new Product(name, brand, price);
                    }
                    stock.myProducts.add(product);
                    VisualizationField.add("[INFO]: Produto cadastrado com sucesso:");
                    VisualizationField.add("Nome: " + product.getName() + " Marca: " + product.getBrand() + " Preço: " + product.getPrice() + " Quantidade: " + product.getQuantity());
                }
            }
            else {
                VisualizationField.add("[ERRO]: Os campos de Nome, Marca e Preço são obrigatórios para adicionar um novo produto!");
            }
        }
    }
    
    /* CONSULTA
        Aqui somente verifica as informações de entrada e procura com o que o utilizador escreveu
        -Se escreveu nome e marca, procura por produto que atendem os 2 requisitos
        -Se escreveu só nome, e deixou marca em branco, só procura pelo nome
        -Se escreveu só marca e deixou nome em branco, só procura pela marca
    */
    class ProductConsultingListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            VisualizationField.clear();
            if ((TFproductConsulting.getText().length() > 0) && (TFbrandConsulting.getText().length() > 0)){
                VisualizationField.add("[INFO]: Consultando os produtos pelo nome: " + TFproductConsulting.getText() + ". Junto a marca: " + TFbrandConsulting.getText());
                for (Product product : stock.myProducts) {
                    if(product.getName().equals(TFproductConsulting.getText()) && product.getBrand().equals(TFbrandConsulting.getText())){
                        VisualizationField.add("Nome: " + product.getName() + " > Marca: " + product.getBrand() + " > Preço: " + product.getPrice() + " > Quantidade: " + product.getQuantity() + "\n");
                    }
                }
            }
            else if(TFproductConsulting.getText().length() > 0){
                VisualizationField.add("[INFO]: Consultando os produtos pelo nome: " + TFproductConsulting.getText());
                for (Product product : stock.myProducts) {
                    if(product.getName().equals(TFproductConsulting.getText())){
                        VisualizationField.add("Nome: " + product.getName() + " > Marca: " + product.getBrand() + " > Preço: " + product.getPrice() + " > Quantidade: " + product.getQuantity() + "\n");
                    }
                }
            }
            else if (TFbrandConsulting.getText().length() > 0){
                VisualizationField.add("[INFO]: Consultando os produtos pela marca: " + TFbrandConsulting.getText());
                for (Product product : stock.myProducts) {
                    if(product.getBrand().equals(TFbrandConsulting.getText())){
                        VisualizationField.add("Nome: " + product.getName() + " > Marca: " + product.getBrand() + " > Preço: " + product.getPrice() + " > Quantidade: " + product.getQuantity() + "\n");
                    }
                }
            }
        }
    }
    
    /* LISTAGEM

        Verifica os checkbox's marcados, dando preferencia para o checkbox de listagem por nome
        Nos dois casos a lógica é parecida.
        -Na listagem por nome ele cria um array e guarda todos os nomes, depois percorre a lista de objetos e printa conforme vai passando na lista ordenada
        -Na listagem por preço, a unica diferença é um método de eliminar repetições na lista, se houver 2 preços iguais, iria printar os mesmos produtos varias vezes
    */
    
    // Classe interna para receber eventos do botao listar produtos
    class ProductListListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            //System.out.printf("Mostrando todos os produtos: \n");
            VisualizationField.clear();
            
            if(ListingName.getState()){
                String[] names = new String[stock.myProducts.size()];
                for (int i = 0; i < names.length; i++) {
                    names[i] = stock.myProducts.get(i).getName();
                }
                Arrays.sort(names); //organiza
                names = new HashSet<String>(Arrays.asList(names)).toArray(new String[0]);
                VisualizationField.add("[INFO]: Listando produtos ordenados pelo nome.");
                for (int i = 0; i < names.length; i++) {
                    for (Product product : stock.myProducts) {
                        if (product.getName().equals(names[i])){
                            VisualizationField.add("Nome: " + product.getName() + " > Marca: " + product.getBrand() + " > Preço: " + product.getPrice() + " > Quantidade: " + product.getQuantity());
                        }
                    }
                }
            }
            else if(ListingPrice.getState()){
                int[] prices = new int[stock.myProducts.size()];
                for (int i = 0; i < prices.length; i++) {
                    prices[i] = Integer.parseInt(stock.myProducts.get(i).getPrice());
                }
                Arrays.sort(prices); //organiza
                prices = Arrays.stream(prices).distinct().toArray(); //remove repetidos 
                VisualizationField.add("[INFO]: Listando produtos ordenados pelo preço.");
                for (int i = 0; i < prices.length; i++) {
                    for (Product product : stock.myProducts) {
                        if (Integer.parseInt(product.getPrice()) == prices[i]){
                            VisualizationField.add("Nome: " + product.getName() + " > Marca: " + product.getBrand() + " > Preço: " + product.getPrice() + " > Quantidade: " + product.getQuantity());
                        }
                    }
                }
            }
        }
    }
    
    
    public Screen(){
        System.out.println("inicio da janela");

        this.setTitle("Padaria");
        
        System.out.println("fim da janela");
        
        // Define o layout manager geral
        GridLayout gridGeral = new GridLayout(4, 1);
        this.setLayout(gridGeral);
        
        Stock stock = new Stock();

        //área para adicionar produto
        Panel product = new Panel();
        product.setLayout(new GridLayout(10, 1));
        product.add(new Label("Adicionar novo produto"));
        
        product.add(new Label("Nome"));
        TFaddName = new TextField("");
        product.add(TFaddName);
        
        product.add(new Label("Marca"));
        TFaddBrand = new TextField("");
        product.add(TFaddBrand);
        
        product.add(new Label("Preço"));
        TFaddPrice = new TextField("");
        product.add(TFaddPrice);
        
        product.add(new Label("Quantidade"));
        TFaddQuantity = new TextField("");
        product.add(TFaddQuantity);

        BaddProduct = new Button("Adicionar");
        product.add(BaddProduct);

        AddProductListener newProduct = new AddProductListener();
        BaddProduct.addActionListener(newProduct);
        
        product.setBackground(Color.green);

        this.add(product);

         //consulta de produto  
        Panel estoque = new Panel();
        estoque.setLayout(new GridLayout(10, 2));
        

        estoque.add(new Label("Consulta de estoque"));
        estoque.add(new Label(""));
        estoque.add(new Label("Nome:"));
        TFproductConsulting = new TextField("");
        estoque.add(TFproductConsulting);
        estoque.add(new Label("Marca:"));
        TFbrandConsulting = new TextField("");
        estoque.add(TFbrandConsulting);
        estoque.add(new Label(""));
        estoque.add(new Label(""));
        estoque.add(new Label(""));
        BproductConsulting = new Button("Consultar");
        estoque.add(BproductConsulting);
        ProductConsultingListener products = new ProductConsultingListener();
        BproductConsulting.addActionListener(products);     
        estoque.setBackground(Color.LIGHT_GRAY);
        this.add(estoque);

        //listagens produtos
        ListingName = new Checkbox("Nome", true);
        ListingPrice = new Checkbox("Preço", false);

        Panel lists = new Panel();
        lists.setLayout(new GridLayout(4, 1));
        lists.add(new Label("Listagens"));
        lists.add(ListingName);
        lists.add(ListingPrice);
        BproductsList = new Button("Listar");
        lists.add(BproductsList);
        ProductListListener productList = new ProductListListener();
        BproductsList.addActionListener(productList);
      
        lists.setBackground(Color.orange);
        this.add(lists);
        
        Panel Visualization = new Panel();
        Visualization.setLayout(new GridLayout(1, 1));
        VisualizationField = new List(10, false);
        Visualization.add(VisualizationField);
        Visualization.setBackground(Color.white);
        this.add(Visualization);
        
        // Para pegar o fechamento da janela
        WindowListener wl = new WindowListener();
        this.addWindowListener(wl);
        
        this.pack();
        this.setVisible(true);
    }
    
    @Override
    public Dimension getPreferredSize() {
        return new Dimension(600, 1000);
    }
            
}

