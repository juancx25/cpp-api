import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { ActivatedRoute } from '@angular/router';
import { Author } from '../entity/Author';
import { AuthorService } from '../service/author/author.service';
import { QuoteService } from '../service/quote/quote.service';
import { response } from 'express';
import { Quote } from '../entity/Quote';

@Component({
  selector: 'fulbo-author-page',
  templateUrl: './author-page.component.html',
  styleUrl: './author-page.component.css'
})
export class AuthorPageComponent {


  author: Author | undefined | null;
  authorQuotes: Quote[] | undefined | null;
  isLoading: boolean = false;

  biographicDataFields = [
    'Nacionalidad',
    'Nacimiento',
    'Fallecimiento',
    'Club favorito',
    'Apodos'
  ];

  constructor(
    private activatedRoute: ActivatedRoute,
    private authorService: AuthorService,
    private quoteService: QuoteService
  ){}

  ngOnInit(){
    this.activatedRoute.params.subscribe(s => {
      const authorId = s["id"];
      authorId ? this.getAuthor(authorId) : this.author = null;
    });
  }

  getAuthor(authorId: string){
    this.isLoading = true;
    this.authorService.getAuthorById(authorId).subscribe(response => {
      if (response.id === authorId){
        this.author = response;
        this.isLoading = false;
        this.getAuthorQuotes(authorId);
      }
    });
  }
  
  getAuthorQuotes(authorId: string){
    this.quoteService.getAllQuotesByAuthorId(authorId).subscribe(response => {
      this.authorQuotes = response;
    });
  }

}
