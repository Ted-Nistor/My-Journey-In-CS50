class Book:
    def __init__(self, title, author, pages, current_page=1):
        self.title = title
        self.author = author
        self.pages = pages
        self.current_page = current_page

    def next_page(self):
        if self.current_page != int(self.pages):
            self.current_page += 1

    def previous_page(self):
        if self.current_page != 1:
            self.current_page -= 1

    def go_to_page(self, page_number):
        if 1 <= page_number <= int(self.pages):
            self.current_page = page_number

    def get_current_page(self):
        return self.current_page

    def get_book_details(self):
        print(f"Title: {self.title}, Author: {self.author}, Pages: {self.pages}")

class Reader:
    def __init__(self, name, book):
        self.name = name
        self.book = book

    def get_reader_details(self):
        print(f"Name: {self.name}")
        self.book.get_book_details()

def main():
    book1 = Book('Call of Cthulhu', 'H.P. Lovecraft', 35)
    reader1 = Reader('Ted', book1)
    reader1.get_reader_details()
    reader1.book.next_page()
    print(reader1.book.get_current_page())
    reader1.book.previous_page()
    print(reader1.book.get_current_page())
    reader1.book.go_to_page(20)
    print(reader1.book.get_current_page())

main()
