import { Component } from '@angular/core';
import { Quote } from '../entity/Quote';
import { ActivatedRoute } from '@angular/router';
import { QuoteService } from '../service/quote/quote.service';
import { AuthorService } from '../service/author/author.service';
import { Author } from '../entity/Author';

@Component({
  selector: 'fulbo-quote-page',
  templateUrl: './quote-page.component.html',
  styleUrl: './quote-page.component.css'
})
export class QuotePageComponent {

  quote: Quote | undefined | null;
  quoteAuthor: Author | undefined;
  isLoading: boolean = false;

  constructor(
    private activatedRoute: ActivatedRoute,
    private quoteService: QuoteService,
    private authorService: AuthorService
  ){}

  ngOnInit(){
    this.activatedRoute.params.subscribe(s => {
      const quoteId = s["id"];
      quoteId ? this.getQuote(quoteId) : this.quote = null;
    });
  }

  getQuote(quoteId: string){
    this.isLoading = true;
    this.quoteService.getQuoteById(quoteId).subscribe(response => {
      if (response.id === quoteId){
        response.creationDate = new Date(response.creationDate);
        this.quote = response;
        this.getQuoteAuthor(response.authorId);
        this.isLoading = false;
      }
    });
  }

  getQuoteAuthor(authorId: string){
    this.isLoading = true;
    this.authorService.getAuthorById(authorId).subscribe(response => {
      if (response.id === authorId){
        this.quoteAuthor = response;
        this.isLoading = false;
      }
    });
  }

}
