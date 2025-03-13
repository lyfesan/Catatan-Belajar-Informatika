
void main() {
  // Variable
  var name = "lyfesan";
  final school = "ITS";
  const age = 20;

  for(int i=0;i<=10;i++) {
    print("Hello World $i");
  }

  print(name);
  print("School : $school");
  print(age);
  print(greet(name: "Lyfe"));
}

//Functions and named parameter
greet ({required String name, int? age}) {
  return "Hello, my name is $name and my age is $age";
}