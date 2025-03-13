import 'dart:convert' as convert;
import 'package:http/http.dart' as http;

void main() async {

  final post = await fetchPost();

  print(post.title);
  print(post.userId);
  // final post = await fetchPost();
  // print(post.title);
  // print(post.userId);

}

// Simulates fetching data
Future<Post> fetchPost() async {
  var uri = Uri.https('jsonplaceholder.typicode.com', '/posts/2');
  
  final response = await http.get(uri);
  //print(response.body);

  Map<String, dynamic> data = convert.jsonDecode(response.body);

  return Post(data["title"], data["userId"]);
}

class Post {
  String title;
  int userId;

  Post(this.title, this.userId);
}