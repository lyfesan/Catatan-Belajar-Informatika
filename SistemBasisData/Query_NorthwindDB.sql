-- Query 1
-- Find the orderDate and ShipperName 
-- from the order that was made by customer named Thomas Hardy
SELECT OrderDate, ShipperName, Orders.CustomerID 
FROM Orders 
JOIN Shippers ON (Orders.ShipperID=Shippers.ShipperID) 
JOIN Customers ON (Orders.CustomerID=Customers.CustomerID) 
WHERE Customers.ContactName = 'Thomas Hardy';

-- Query 2
-- Get the employee born in January, sort by their name
SELECT * FROM Employees 
WHERE MONTH(Employees.BirthDate) = 1 
ORDER BY Employees.FirstName, Employees.LastName;

-- Query 3
-- Number of product for each category
SELECT Categories.CategoryName , COUNT(*) AS Count FROM Categories JOIN Products 
WHERE Categories.CategoryID=Products.CategoryID 
GROUP BY Categories.CategoryName;

-- Query 4
-- Find the most expensive product
SELECT * FROM Products 
WHERE Products.Price = (SELECT MAX(Products.Price) FROM Products);

-- Query 5
-- Find the average price for each category
SELECT Categories.CategoryName, AVG(Products.Price) 
FROM Categories JOIN Products ON (Categories.CategoryID=Products.CategoryID) 
GROUP BY Categories.CategoryName;
