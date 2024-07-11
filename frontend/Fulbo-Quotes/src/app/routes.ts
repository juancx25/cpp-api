import { Routes } from "@angular/router";
import { AuthorPageComponent } from "./feature/author-page/author-page.component";
import { QuotePageComponent } from "./feature/quote-page/quote-page.component";

const routeConfig: Routes = [
    { path: 'author/:id', component: AuthorPageComponent },
    { path: 'quote/:id', component: QuotePageComponent },
  ];

export default routeConfig;