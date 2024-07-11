import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { Quote } from '../../entity/Quote';
import { AppSettings } from '../../../../../AppSettings/AppSettings';

@Injectable({
  providedIn: 'root'
})
export class QuoteService {

  constructor(
    private httpClient: HttpClient
  ) { }

  getQuoteById(quoteId: string): Observable<Quote>{
    return this.httpClient.get<Quote>(`${AppSettings.API_ENDPOINT}/quote/${quoteId}`);
  }

  getAllQuotesByAuthorId(authorId: string): Observable<Quote[]>{
    return this.httpClient.get<Quote[]>(`${AppSettings.API_ENDPOINT}/quotes?authorId=${authorId}`);
  }

}
