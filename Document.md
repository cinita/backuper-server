### Sign up

### Sign in
## Request
1. Host
   1. POST sign_in
2. Header
   1. Content-Type : application/json;charset=UTF-8
   2. Accept: application/json
3. Response
        ```
        {
            "code": 0,
            "message": "sucess",
            "data": {
                "user_token": "abc"
            }
        }
        ```

# Post image
# Request
1. POST /upload
2. Content-Type : multipart/form-data;boundary=abc
3. Accept: application/json
4. User-Token: abc
# Response
```
{
    "code": 0,
    "message": "sucess"
    "data": {}
}
```