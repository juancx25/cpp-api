import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { AuthorPageComponent } from './author-page/author-page.component';
import { SharedModule } from '../shared/shared.module';
import { QuotePageComponent } from './quote-page/quote-page.component';

@NgModule({
  declarations: [
    AuthorPageComponent,
    QuotePageComponent
  ],
  imports: [
    CommonModule,
    SharedModule
  ]
})
export class FeatureModule { }
