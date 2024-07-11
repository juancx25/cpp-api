import { Component, Input } from '@angular/core';
import { DomSanitizer } from '@angular/platform-browser';

@Component({
  selector: 'fulbo-img',
  templateUrl: './image.component.html',
  styleUrl: './image.component.css'
})
export class ImageComponent {
  @Input() image: any;
  imageToShow: any;


  constructor(private _sanitizer: DomSanitizer){}

  ngOnInit(){
    if (this.image){
      this.imageToShow = this._sanitizer.bypassSecurityTrustResourceUrl('data:image/jpg;base64,' + this.image);
    } else {
      // TODO: show a placeholder image
    }
  }
}
