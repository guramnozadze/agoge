package main

import (
  "fmt"
  "time"
)


func main(){

  // ch := make(chan string)
  // go boring("Boring!", ch)
  fmt.Println(5/2)  
  var myZero int
  fmt.Println(myZero)
  ch := boringChReturn("Boring")
  chg := boringChReturn("GUKA")

  for i := 0; i < 5; i++{
    fmt.Printf("You say: %q\n", <-ch)
    fmt.Printf("You say: %q\n", <-chg)
  }

  fmt.Println("You're boring; I am leaving.")
}

func boring(msg string, c chan string){
  for i:=0;;i++{
    c <- fmt.Sprintf("%s %d", msg, i)
    time.Sleep(time.Millisecond * 500)
  }
}

func boringChReturn(msg string) <- chan string{
  c := make(chan string)
  go func(){
    for i :=0; ; i++{
      c <- fmt.Sprintf("%s %d", msg, i)
      time.Sleep(time.Millisecond * 500)
    }
  }()
  return c
}
