package main

import (
	"fmt"
	"net/http"
)

func fetchData(url string) (int, error) {
	// ?
  res, err := http.Get("https://example.com/api/resource")
  if err != nil{
    return 0, fmt.Errorf("network error: %v", err)
  }
  defer res.Body.Close()

  if res.StatusCode != http.StatusOk{
      return res.StatusCode,fmt.Errorf("non-OK HTTP status: %s")
 
  }
}

