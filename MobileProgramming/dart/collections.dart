void main () {

  // Lists
  var scores = [50, 75, 80, 90, "test"];
  List<int> height = [190, 175, 170];
  print(scores[scores.length-1]);
  height.add(150);
  print(height);
  scores.removeLast();
  print(scores);

  // Sets
  Set<String> names = {"Lisa", "Linda", "Luna"};
  names.add("Lira");
  print(names.length);

  // Maps
  Map<String, String> planets = {
    "first":"mercury",
    "second":"venus",
    "third":"earth",
    "fourth": "mars",
    "fifth" : "jupiter",
    "sixth" : "saturn",
    "seventh" : "uranus"
  };
  print(planets);
  planets["eighth"] = "neptune";
  print(planets["eighth"]);
  // Maps properties
  print(planets.containsKey("third"));
  print(planets.containsValue("pluto"));
  // Maps add/remove operations
  planets["ninth"] = "pluto";
  planets.remove("ninth");
  


  // Lambda expression
  List<int> weights = [50, 65, 55, 78, 62, 70];
  // Filtering using arrow and lambda
  for(int weight in weights.where((w) => w > 50)) {
    print("Weight is $weight");
  }

}