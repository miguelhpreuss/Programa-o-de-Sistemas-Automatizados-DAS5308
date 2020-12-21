/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;


/**
 *
 * @author Pollyana
 */
public class Product {
    private String name;
    private String brand;
    private String price;
    private String quantity;

    public Product(String name, String brand, String price) {
        this.name = name;
        this.brand = brand;
        this.price = price;
        this.quantity = "1";
    }

    public Product(String name, String brand, String price, String quantity) {
        this.name = name;
        this.brand = brand;
        this.price = price;
        this.quantity = quantity;
    }

    public String getName() {
        return this.name;
    }
    public String getBrand() {
        return this.brand;
    }

    public String getPrice() {
        return this.price;
    }
    
    public String getQuantity() {
        return quantity;
    }
 
    public void setPrice(String price) {
        this.price = price;
    }
    
    public void setQuantity(String quantity) {
        this.quantity = quantity;
    }

}
