use std::collections::HashMap;

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
}