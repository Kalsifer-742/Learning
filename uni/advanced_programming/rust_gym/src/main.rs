use std::fmt;
use std::collections::{HashMap, LinkedList};
use std::f32::consts::PI;
use std::fmt::{Display, Formatter};
use std::fs::ReadDir;
use std::ops::{Add, Sub};
use std::slice::Iter;

mod sentence;
mod test;

use sentence::Sentence;
use test::magic_sentence;

#[allow(dead_code)]
fn string_reverse(str: &str) -> String {
    let mut result = String::default();

    for lettera in str.chars().rev() {
        result.push(lettera);
    }

    return result;
}

fn string_reverse_giusta(str: &str) -> String {
    let mut result = String::default();

    for lettera in str.chars() {
        result.insert(0, lettera);
    }

    return result;
}

fn bigger(a: i32, b: i32) -> i32 {
    return if a > b { a } else { b };
}

fn multiply(a: i32, b: i32, c: f32) -> f64{
    return (a as f32 * b as f32 * c) as f64;
}

const SPEED_OF_LIGHT: u64 = 299_792_458; //m/s
fn e_equals_mc_squared(mass: f32) -> f32 {
    return mass * SPEED_OF_LIGHT.pow(2) as f32;
}

fn max_min(vec: Vec<i32>) -> (i32, i32) {
    let mut max = i32::MIN;
    let mut min = i32::MAX;
    for n in vec {
        if n > max { max = n; }
        if n < min { min = n; }
    }

    return (max, min);
}

fn lord_farquaad(str: String) -> String {
    return str.replace("e", "💥");
}

fn hashmap_test(hm: &HashMap<String, f32>, forniture: String) -> f32 {
    return match hm.get(&forniture) {
        None => { -1.0 }
        Some(price) => { *price }
    }
}

fn append(mut str: String) -> String {
    str.push_str("foobar");
    return str;
}

fn is_armstrong(number: u32) -> bool {
    let number_length = number.to_string().chars().count();
    let mut sum = 0;
    for char in number.to_string().chars() {
        sum += char.to_digit(10).unwrap().pow(number_length as u32);
    }

    if sum == number {
        return true
    } else {
        return false;
    }
}

fn matrix_transposition(matrix: ((i32, i32), (i32, i32))) -> ((i32, i32), (i32, i32)) {
    let ((x, y), (z, w)) = matrix;
    return ((x, z), (y, w));
}

fn modify_odd(slice: &mut [i32]) {
    for number in slice {
        if *number % 2 != 0 {
            *number = 0;
        }
    }
}

fn vec_creator() -> Vec<i32> {
    let mut vec = Vec::new();
    for number in 0..101 {
        vec.push(number);
    }
    return vec;
}

fn count_character(string: &str) -> HashMap<char, i32>{
    let mut letters_count = HashMap::new();
    for ch in string.chars() {
        letters_count.entry(ch).and_modify(|c| {*c += 1}).or_insert(1);
    }
    return letters_count;
}

fn split_at_value(slice: &[i32], value: i32) -> Option<(&[i32], &[i32])>{
    let index = match slice.iter().position(|x| *x == value) {
        None => return None,
        Some(ind) => ind,

    };
    return Some(slice.split_at(index));
}

fn sub_slice(vec1: Vec<i32>, vec2: Vec<i32>) {
    let mut counter = 0;
    for value in &vec2 {
        if vec1.contains(value) {
            counter += 1;
        }
    }
    if counter == vec2.len() {
        println!("{:?}", vec2);
    } else {
        print!("Not found");
    }
}

fn fn_max(vec: &Vec<i32>) -> i32 {
    let mut max = i32::MIN;
    for x in vec {
        if *x > max {
            max = *x;
        }
    }
    return max;
}

fn swap(vec: &mut Vec<i32>) {
    let tmp = vec[0];
    let len = vec.len();
    vec[0] = vec[len - 1];
    vec[len - 1] = tmp;
}

fn is_sorted(vec: Vec<i32>) -> bool {
    return vec.windows(2).all(|pair| pair[0] <= pair[1]);
}

fn insert_if_longer(vec: &mut Vec<String>, string: String) {
    if string.chars().count() > 10 {
        vec.push(string);
    }
}

fn build_vector(it: Iter<i32>) -> Vec<i32> {
    let mut vec = Vec::new();
    for n in it {
        vec.push(*n);
    }
    return vec;
}

fn get_max_ind(vec: &[i32]) -> usize {
    let mut max = i32::MIN;
    let mut max_index = 0;
    for (ind, n) in vec.iter().enumerate() {
        if *n > max {
            max = *n;
            max_index = ind;
        }
    }
    return max_index;
}

fn pancake_sort(vec: &mut Vec<i32>) {
    let mut count = 0;
    loop {
        //println!("{:?}", vec);
        let max_index = get_max_ind(&vec[count..]);
        //println!("count {}, ind: {}", count, max_index + count);
        vec[count ..= max_index + count].reverse();
        //println!("reverse {:?}", vec);
        count += 1;
        if count == vec.len() - 1 {
            break;
        }
    }
}

fn merge(arr1: &[i32], arr2: &[i32]) -> Vec<i32> {
    let mut merge = [arr1, arr2].concat();
    merge.sort();
    return Vec::from(merge);
}

#[allow(dead_code)]
enum Operation {
    Add,
    Sub,
    Mul,
    Div,
}

enum Expression {
    Number(i32),
    Operation(Box<Expression>, Box<Expression>, Operation),
}

fn evaluate_expression(exp : Expression) -> i32 {
    return match exp {
        Expression::Number(x) => x,
        Expression::Operation(left, right, op) => {
            let l = evaluate_expression(*left);
            let r = evaluate_expression(*right);
            match op {
                Operation::Add => l + r,
                Operation::Sub => l - r,
                Operation::Mul => l * r,
                Operation::Div => l / r,
            }
        }
    }
}

//it was fun to write meme code
fn is_it_luhn(input: &str) -> bool {
    input.trim()
        .split_whitespace()
        .map(|group| {
            group.chars()
                .map(|digit| digit.to_digit(10).unwrap())
                .collect()
        })
        .collect::<Vec<Vec<u32>>>()
        .concat()
        .iter()
        .enumerate()
        .map(|(index, digit)| {
            if index % 2 == 0 {
                if *digit * 2 <= 9 {
                    *digit * 2
                } else {
                    *digit * 2 - 9
                }
            } else {
                *digit
            }
        }).collect::<Vec<u32>>()
        .iter()
        .sum::<u32>() % 10 == 0
}

#[allow(dead_code)]
enum Fuel {
    Diesel,
    Gasoline,
    LPG,
    Methane,
    Electric
}

#[allow(dead_code)]
enum IP {
    IPV4(u8, u8, u8, u8),
    IPV6(u16, u16, u16, u16, u16, u16, u16, u16)
}

#[allow(dead_code)]
struct Point {
    x: f64,
    y: f64,
    z: f64

}

fn recognise_owner<'a>(plates: &'a HashMap<&str, &str>, input: &str) -> Option<&'a str> {
    return match plates.get(input) {
        None => None,
        Some(owner) => Some(owner)
    }
}

#[derive(Eq, Hash, PartialEq)]
enum Item {
    Coke,
    Coffee,
    Chips
}

#[allow(dead_code)]
enum Coin {
    Cents10,
    Cents20,
    Cents50,
    Euro1,
    Euro2
}

impl Coin {
    fn to_cents(&self) -> u32 {
        return match &self {
            Coin::Cents10 => 10,
            Coin::Cents20 => 20,
            Coin::Cents50 => 50,
            Coin::Euro1 => 100,
            Coin::Euro2 => 200
        };
    }
}

struct VendingMachine {
    coins: u32,
    items: HashMap<Item, usize> //This field should associate an Item type to the number of available items to buy
}

impl VendingMachine {
    fn new(items: HashMap<Item, usize>) -> Self {
        Self {
            coins: 0, //cents
            items
        }
    }

    fn add_item(&mut self, item: Item, quantity: usize) {
        self.items.entry(item).and_modify(|storage| *storage += quantity).or_insert(quantity);
    }

    fn insert_coin(&mut self, coin: Coin) -> Result<&str, &str> {
        self.coins += coin.to_cents();
        return Ok("Credit increased successfully");
        //return Ok(format!("Credit increased successfully to {}", self.coins).as_str());
    }

    fn get_item_price(&self, item: &Item) -> u32 {
        return match item {
            Item::Coke => 100,
            Item::Coffee => 50,
            Item::Chips => 150,
        };
    }

    fn buy(&mut self, item: Item) -> Result<u32, &str> {
        if self.coins - self.get_item_price(&item) > 0 {
            self.coins -= self.get_item_price(&item);
            self.items.entry(item).and_modify(|storage| *storage -= 1);
            return Ok(self.coins);
        } else {
            return Err("Credit is not sufficient");
        }
    }
}
#[derive(Debug)]
struct Date(u8, u8, u16);

#[derive(Debug)]
struct Hour(u8, u8);

#[derive(Debug)]
struct BoxShipping {
    name: String,
    barcode: String,
    shipment_date: Date,
    shipment_hour: Hour
}

impl fmt::Display for Date {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}/{}/{}", self.0, self.1, self.2)
    }
}

impl fmt::Display for Hour {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:0>2}:{:02}", self.0, self.1) //different ways to format in the same way
    }
}

impl fmt::Display for BoxShipping {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "name: {} | barcode: {} | shipment: {}-{}", self.name, self.barcode, self.shipment_date, self.shipment_hour)
    }
}

trait Split<'a> {
    type ReturnType;
    fn split(&'a self) -> (Self::ReturnType, Self::ReturnType);
}

impl<'a> Split<'a> for String {
    type ReturnType = &'a str;
    fn split(&'a self) -> (Self::ReturnType, Self::ReturnType) {
        self.split_at(self.len()/2)
    }
}

impl<'a> Split<'a> for &[i32] {
    type ReturnType = &'a [i32];
    fn split(&'a self) -> (Self::ReturnType, Self::ReturnType) {
        self.split_at(self.len()/2)
    }
}

impl<'a> Split<'a> for LinkedList<f64> {
    type ReturnType = LinkedList<f64>;
    fn split(&self) -> (Self::ReturnType, Self::ReturnType) {
        let mut left = self.clone();
        let right = left.split_off(self.len()/2);
        (left, right)
    }
}

struct Point2D {
    x: f32,
    y: f32
}

#[allow(dead_code)]
struct Circle {
    radius: f32,
    center: Point2D
}

struct Rectangle{
    top_left: Point2D,
    bottom_right: Point2D
}

impl Default for Point2D{
    fn default() -> Self {
        Self {
            x: 0.0,
            y: 0.0,
        }
    }
}

impl Default for Circle {
    fn default() -> Self {
        Self {
            radius: 1.0,
            center: Point2D::default()
        }
    }
}

impl Default for Rectangle{
    fn default() -> Self {
        Self {
            top_left: Point2D { x: -1.0, y: 1.0 },
            bottom_right: Point2D { x: 1.0, y: -1.0 }
        }
    }
}

impl Add for Point2D {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self {
            x: self.x + rhs.x,
            y: self.y + rhs.y,
        }
    }
}

impl Sub for Point2D {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self {
            x: self.x - rhs.x,
            y: self.y - rhs.y,
        }
    }
}

struct Area {
    value: f32
}

impl Default for Area {
    fn default() -> Self {
        Self{
            value: 0.0
        }
    }
}

impl Display for Area {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        write!(f, "Area is {} cm²", self.value)
    }
}

trait GetArea {
    fn get_area(&self) -> Area;
}

impl GetArea for Point2D {
    fn get_area(&self) -> Area {
        Area {
            value: 0.0
        }
    }
}

impl GetArea for Circle {
    fn get_area(&self) -> Area {
        Area {
            value: PI * self.radius.powi(2)
        }
    }
}

impl GetArea for Rectangle {
    fn get_area(&self) -> Area {
        let base = self.top_left.x - self.bottom_right.x;
        let height = self.top_left.y - self.bottom_right.y;

        Area {
            value: (base * height).abs()
        }
    }
}

impl Add for Area{
    type Output = Area;

    fn add(self, rhs: Self) -> Self::Output {
        Self {
            value: self.value + rhs.value
        }
    }
}

fn sum_area(input: &[&dyn GetArea]) -> f32 {
    let mut result = 0.0;
    for geometric_form in input {
        result += geometric_form.get_area().value;
    }
    return result;
}

fn skip_prefix<'a>(telephone_number: &'a str, prefix: &str) -> &'a str {
    telephone_number.trim_start_matches(prefix)
}

struct Chair<'a> {
    color: &'a str,
    quantity: &'a usize
}

struct Wardrobe<'a> {
    color: &'a str,
    quantity: &'a usize
}

trait Object {
    fn build(&self) -> &str;
    fn get_quantity(&self) -> String;
}

impl<'a> Object for Chair<'a> {
    fn build(&self) -> &str {
        "Chair has been built"
    }

    fn get_quantity(&self) -> String {
        format!("There are {} Chair", self.quantity)
    }
}

impl<'a> Object for Wardrobe<'a> {
    fn build(&self) -> &str {
        "Wardrobe has been built"
    }

    fn get_quantity(&self) -> String {
        format!("There are {} Wardrobe", self.quantity)
    }
}

impl Display for Chair<'_> {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        if *self.quantity > 0 {
            write!(f, "There are {} {} Chair", self.quantity, self.color)
        } else {
            write!(f, "There are 0 Chair")
        }
    }
}

impl Display for Wardrobe<'_> {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        if *self.quantity > 0 {
            write!(f, "There are {} {} Wardrobe", self.quantity, self.color)
        } else {
            write!(f, "There are 0 Wardrobe")
        }
    }
}

#[derive(PartialEq, Eq)]
enum Role {
    GUEST,
    USER,
    ADMIN,
}

#[derive(PartialEq, Eq, Hash, Copy, Clone)]
enum Permission {
    READ,
    WRITE,
    EXECUTE
}

struct Actions{
    action: String,
    permission: HashMap<Permission, bool>
}

struct User{
    name: String,
    role: Role,
    actions: Vec<Actions>
}

trait Auth{
    fn check_permission(&self, action: &str, permission_type: &Permission) -> bool;
    fn can_write(&self, string: &str) -> bool;
    fn can_read(&self, string: &str) -> bool;
    fn can_execute(&self, string: &str) -> bool;
}

impl Auth for User{
    fn check_permission(&self, action: &str, permission_type: &Permission) -> bool {
        for self_action in self.actions.iter() {
            if self_action.action == action {
                if self_action.permission.get(permission_type).is_some() {
                    if *self_action.permission.get(permission_type).unwrap() {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    fn can_write(&self, string: &str) -> bool {
        self.check_permission(string, &Permission::WRITE)
    }

    fn can_read(&self, string: &str) -> bool {
        self.check_permission(string, &Permission::READ)
    }

    fn can_execute(&self, string: &str) -> bool {
        self.check_permission(string, &Permission::EXECUTE)
    }
}

impl Default for Actions {
    fn default() -> Self {
        Self {
            action: "".to_string(),
            permission: HashMap::from([
                (Permission::READ, false),
                (Permission::WRITE, false),
                (Permission::EXECUTE, false)
            ])
        }
    }
}

impl Actions {
    fn new(action: String, read: bool, write: bool, execute: bool) -> Self {
        Self {
            action,
            permission: HashMap::from([
                (Permission::READ, read),
                (Permission::WRITE, write),
                (Permission::EXECUTE, execute)
            ])
        }
    }
}

impl Default for User {
    fn default() -> Self {
        Self {
            name: "Guest".to_string(),
            role: Role::GUEST,
            actions: vec![],
        }
    }
}

impl User {
    fn change_role(&mut self, role: Role) -> Result<(), String> {
        return match self.role {
            Role::ADMIN => { self.role = role; Ok(()) }
            Role::USER => { match role {
                Role::ADMIN => Err(String::from("Cannot change role to ADMIN")),
                role => { self.role = role; Ok(()) }
            } }
            Role::GUEST => { match role {
                Role::GUEST => { self.role = role; Ok(()) }
                _ => Err(String::from("Cannot change role when GUEST"))
            } }
        }
    }
}

fn sudo_change_permission(user: &mut User, string: String, permission: Permission, value: bool) {
    user.actions.iter_mut().for_each(|a| {
        if a.action == string {
            a.permission.insert(permission, value);
        }
    })
}

fn main() {
    let str = "Ciao";
    //println!("{}", str);
    //let rev_str = string_reverse(str);
    let rev_str = string_reverse_giusta(str);
    println!("{}", rev_str);

    println!("{}", bigger(3, 2));

    println!("{}", multiply(3, 2, 2.5));

    println!("{}", e_equals_mc_squared(2.5));

    let (max, min) = max_min(vec![1, 2, 3, 4, 5, 6]);
    println!("max:{} / min:{}", max, min);

    println!("{}", lord_farquaad(String::from("Ceiaeeeo")));

    let mut forniture: HashMap<String, f32> = HashMap::new();
    forniture.insert(String::from("Tavolo da caffè"), 30.0);
    forniture.insert(String::from("Poltrona"), 99.99);
    forniture.insert(String::from("Divano"), 500.0);
    println!("{:.2}", hashmap_test(&forniture, String::from("Poltrona")));
    println!("{:.2}", hashmap_test(&forniture, String::from("Comodino")));

    let str = String::from("pacman is eating the ");
    let appended_str = append(str.clone());
    println!("original: {}\nedited: {}", str, appended_str);

    println!("armostrong? {} {}", 10, is_armstrong(10));
    println!("armostrong? {} {}", 153, is_armstrong(153));

    let matrix = ((1, 2), (3, 4));
    let transposed_matrix = matrix_transposition(matrix);
    println!("original\n{:?}\ntransposed\n{:?}", matrix, transposed_matrix);

    let mut array = [1,2,3,4,5];
    modify_odd(&mut array);
    println!("{:?}", array);

    let mut array2 = vec_creator();
    modify_odd(&mut array2);
    println!("{:?}", array2);

    let ascii_string = "ciao come va?";
    #[allow(unused_variables)]
    let hashmap = count_character(ascii_string);
    //println!("{:?}", hashmap);

    let array_to_be_splitted = [1,2,3,4,5,6,7,8,9,10];
    let (slice1, slice2) = split_at_value(&array_to_be_splitted, 4).expect("The slit value is not present in the array");
    println!("slice1: {:?} - slice2: {:?}", slice1, slice2);

    let array = Vec::from([1,2,3,4,5,6]);
    let sub_array = Vec::from([3,4,5]);
    sub_slice(array, sub_array);

    let mut array = Vec::from([1,2,3,4,5,6]);
    println!("max: {}", fn_max(&array));
    swap(&mut array);
    println!("swap: {:?}", array);

    let array = Vec::from([2,3,4]);
    println!("{:?}", is_sorted(array));

    let mut array_of_strings = vec![String::from("ciao"), String::from("come"), String::from("va?")];
    println!("{:?}", array_of_strings);
    insert_if_longer(&mut array_of_strings, String::from("banana"));
    insert_if_longer(&mut array_of_strings, String::from("parolamoltolunga"));
    println!("{:?}", array_of_strings);

    let array = [1,2,3,4];
    let vec = build_vector(array.iter());
    println!("{:?}", vec);

    let mut array = Vec::from([0,9,5,4,3,7,2,1,3,4,7,5,3,2]);
    pancake_sort(&mut array);
    println!("{:?}", array);

    let array = [1,3,2,2,5,-5];
    let vec = merge(&array[0..3], &array[3..6]);
    println!("{:?}", vec);

    enum IntOrString {
        Integer(i32),
        String(String),
    }

    #[allow(unused_variables)]
    let vec = vec![IntOrString::Integer(32), IntOrString::String(String::from("midd")), IntOrString::Integer(64)];

    let eval = evaluate_expression(
        Expression::Operation(Box::new(Expression::Number(3)), Box::new(Expression::Number(3)), Operation::Mul)
    );
    println!("3x3 = {}", eval);
    let eval = evaluate_expression(
        Expression::Operation(Box::new(Expression::Operation(Box::new(Expression::Number(2)), Box::new(Expression::Number(8)), Operation::Sub)), Box::new(Expression::Number(3)), Operation::Mul)
    );
    println!("(2-8)x3 = {}", eval);

    
    let lun_number = "4539 3195 0343 6467";
    println!("{}", is_it_luhn(lun_number));

    let plates = HashMap::from([
        ("GR·091JW", "Mario Rossi"),
        ("ER·929NG", "Baldo Star")
    ]);
    println!("{}", recognise_owner(&plates, "ER·929NG").unwrap());

    let mut vending_machine = VendingMachine::new(HashMap::from([
        (Item::Coke, 3),
        (Item::Coffee, 10),
    ]));

    vending_machine.add_item(Item::Chips, 1);
    println!("{}", vending_machine.insert_coin(Coin::Euro2).unwrap());
    println!("{}", vending_machine.get_item_price(&Item::Coffee));
    match vending_machine.buy(Item::Chips) {
        Ok(change) => println!("change: {}", change),
        Err(error) => println!("{}", error),
    }

    let box_shipping = BoxShipping {
        name: String::from("Youth"),
        barcode: String::from("1128403"),
        shipment_date: Date(12, 01, 2001),
        shipment_hour: Hour(9, 0),
    };

    println!("{:?}", &box_shipping);
    println!("{}", &box_shipping);

    let mut first_sentence = Sentence::new_default();
    first_sentence.new("Hello my name was cool yesterday");
    let mut second_sentence = Sentence::new_default();
    second_sentence.new("Hi my name is cool");
    let mut sentences = HashMap::from([
        (0, first_sentence),
        (1, second_sentence)
    ]);

    let magic = magic_sentence(&mut sentences, 0, 1).unwrap();
    println!("{:?}", magic.words);

    let circle = Circle::default();
    let rectangle = Rectangle::default();
    println!("Circle area: {}", circle.get_area());
    println!("Rectangle area: {}", rectangle.get_area());
    println!("sum of areas is: {}", sum_area(&[&circle, &rectangle]));

    let number = "+391234567890";
    let prefix = "+39";
    println!("trimmed number {}", skip_prefix(number, prefix));

    let chair = Chair { color: "red", quantity: &2 };
    let wardrobe = Wardrobe { color: "brown", quantity: &5 };
    println!("{}", chair.build());
    println!("{}", chair.get_quantity());
    println!("{}", wardrobe.build());
    println!("{}", wardrobe);

    let mut user = User::default();
    user.actions.push(Actions::new(String::from("Parlare"), true, true, false));
    println!("User può parlare ? {}", user.can_read("Parlare"));
    match user.change_role(Role::USER) {
        Ok(_) => { println!("Ok") }
        Err(e) => { println!("{e}") }
    }
    sudo_change_permission(&mut user, "Parlare".to_string(), Permission::READ, false);
    println!("User può parlare ? {}", user.can_read("Parlare"));
}
