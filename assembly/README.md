### TCP server
- Wrote a tcp server in assembly, serves GET and POST.
- It has forking ability and serve multiple clients without blocking a single client.
- Currently it serves dynamic response as well but that was suited for my usecase, you can tweak it as per your needs and where you run it. 
- For understanding purpose remove the dynamic response and just get static response.
- Requires knowledge of caller saved and callee saved registers to understand the code.
