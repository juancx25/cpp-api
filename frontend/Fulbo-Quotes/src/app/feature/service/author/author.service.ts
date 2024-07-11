import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Author } from '../../entity/Author';
import { AppSettings } from '../../../../../AppSettings/AppSettings';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class AuthorService {

  constructor(
    private httpClient: HttpClient
  ) { }

  getAuthorById(authorId: string): Observable<Author>{
    return this.httpClient.get<Author>(`${AppSettings.API_ENDPOINT}/author/${authorId}`);
  }

}
