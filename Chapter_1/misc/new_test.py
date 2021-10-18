while True:
    try:
        got = input()
        print(got)
    except EOFError:
        break
