import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { HeaderComponent } from './header/header.component';
import { SidebarComponent } from './sidebar/sidebar.component';
import { LoadingSpinnerComponent } from './loading-spinner/loading-spinner.component';
import { ImageComponent } from './image/image.component';



@NgModule({
  declarations: [
    HeaderComponent,
    SidebarComponent,
    LoadingSpinnerComponent,
    ImageComponent
  ],
  imports: [
    CommonModule,
    NgbModule
  ],
  exports: [
    HeaderComponent,
    SidebarComponent,
    LoadingSpinnerComponent,
    ImageComponent
  ]
})
export class SharedModule { }
