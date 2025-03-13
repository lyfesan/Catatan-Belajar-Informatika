void main() {
  var noodles = MenuItem("Vegetable Noodles", 9.99);
  var pizza = Pizza("Cheese Pizza", 12.99, ["mushrooms", "peppers"]);
  
  print(noodles.format());
  print(pizza.format());

  var foods = Collection<MenuItem>(
    "Menu Items",
    [noodles, pizza]
  );

  var random = foods.randomItem();
  print(random);
}

class MenuItem {
  String title;
  double price;

  MenuItem(this.title, this.price);

  String format() {
    return "$title --> \$$price";
  }
}

// Inheritance
class Pizza extends MenuItem {
  List<String> toppings;
  
  Pizza(super.title, super.price, this.toppings);
  
  @override
  String format() {
    var formattedToppings = "Contains:";
    for(final t in toppings) {
      formattedToppings += " $t";
    }
    return "$title --> \$$price \n$formattedToppings";
  }
}

// Generics
class Collection<T> {
  String name;
  List<T> data;

  Collection(this.name, this.data);

  T randomItem() {
    data.shuffle();
    return data[0];
  }
}