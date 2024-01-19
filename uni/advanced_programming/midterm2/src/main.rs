mod odd_module {
    pub const CONSTANT: i32 = 123;
}

mod even_module {
    pub const CONSTANT: i32 = 246;
}

mod getter_function {
    pub fn get_constant(value: u32) -> i32 {
        if value % 2 != 0 {
            // use crate::odd_module::CONSTANT;
            // return CONSTANT;
            super::odd_module::CONSTANT
        } else {
            super::even_module::CONSTANT
        }
    }
}

use std::cell::RefCell;
use std::fmt::{Debug, Display, Formatter, write};
use std::iter::zip;
use std::ops::Add;
use std::rc::Rc;
use crate::getter_function::get_constant;

trait CloneAndDouble {
    fn clone_and_double(&self) -> Self;
}

impl<T: Clone + Add<Output = T>> CloneAndDouble for T {
    fn clone_and_double(&self) -> Self {
        self.clone() + self.clone()
    }
}

trait Unknown {
    fn serialize(&self) -> String;
}

impl Unknown for i32 {
    fn serialize(&self) -> String {
        self.to_string()
    }
}

impl Unknown for String {
    fn serialize(&self) -> String {
        self.clone()
    }
}

impl<T: Debug> Unknown for Vec<T> {
    fn serialize(&self) -> String {
        // let mut result = String::new();
        // for v in self {
        //     result.push_str(format!("{:?}", v).as_str());
        // }
        // return  result;
        format!("{:?}", self)
    }
}

#[allow(dead_code)]
fn get_vec<T: Unknown>() -> Vec<T> {
    Vec::<T>::new()
}

#[allow(dead_code)]
fn get_vec_2() -> Vec<Box<dyn Unknown>> {
    Vec::new()
}

#[allow(dead_code)]
fn print_vec(input: &Vec<Box<dyn Unknown>>) {
    for v in input {
        println!("{:?}", v.serialize());
    }
}

struct BinIter {
    n: u32,
    l: usize
}

impl BinIter {
    fn new(n: u32, l: usize) -> Self {
        Self { n, l }
    }
}

impl Iterator for BinIter {
    type Item = bool;

    //meme implementation. experimenting with rust
    fn next(&mut self) -> Option<Self::Item> {
        let binary = format!("{:b}", self.n);

        return if self.l == 0 {
            None
        } else if binary.chars().nth(self.l-1).unwrap() == '0' {
            self.l -= 1;
            Some(false)
        } else {
            self.l -= 1;
            Some(true)
        }
    }
}

struct Node<T> {
    element: T,
    prev: Option<Rc<RefCell<Node<T>>>>,
    next: Option<Rc<RefCell<Node<T>>>>
}

struct List<T> {
    head: Option<Rc<RefCell<Node<T>>>>,
    tail: Option<Rc<RefCell<Node<T>>>>,
    size: usize
}

impl<T: PartialEq> PartialEq for Node<T> {
    fn eq(&self, other: &Self) -> bool {
        self.element == other.element
    }
}

impl<T: Display> Display for Node<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f, "<{}>", self.element)
    }
}

impl<T: PartialEq> PartialEq for List<T> {
    fn eq(&self, other: &Self) -> bool {
        let mut current_head = self.head.clone();
        let mut other_current_head = other.head.clone();

        loop {
            if let (Some(current_node), Some(other_current_node)) = (current_head, other_current_head) {
                if current_node.borrow().element != other_current_node.borrow().element {
                    return false;
                }
                current_head = current_node.borrow().next.clone();
                other_current_head = other_current_node.borrow().next.clone();
            } else {
                return false;
            }
        }
    }
}

impl<T: Display> Debug for List<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        let mut current_head = self.head.clone();
        loop {
            if let (Some(current_node)) = current_head {
                write!(f, "{}", current_node.borrow().element)?;
                current_head = current_node.borrow().next.clone();
            } else { break }
        }
        Ok(())
    }
}

impl<T: Display> List<T> {
    fn new() -> List<T> {
        List {
            head: None,
            tail: None,
            size: 0
        }
    }

    fn print_list(&self) {
        println!("{:?}", *self);
    }
}

fn main() {
    println!("{}", get_constant(1));

    let bin = BinIter::new(8, 4);
    for b in bin {
        match b {
            true => { print!("1") }
            false => { print!("0") }
        }
    }
    println!();
}
