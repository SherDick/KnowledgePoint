package main

import "fmt"

type user struct {
	name  string
	email string
}

func (u user) notify() {
	fmt.Println("Email is %d", u.email)
}

func (u *user) changeEmail(email string) {
	u.email = email
}

func main() {
	Sher := user{name: "Sher", email: "Sher@oldexample.com"}
	Sher.notify()
	Sher.changeEmail("SherDick@example.com")
	Sher.notify()
}
