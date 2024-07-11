import { Component } from '@angular/core';
import { SharedModule } from './shared/shared.module';
import { FeatureModule } from './feature/feature.module';
import { RouterModule } from '@angular/router';
import { AppModule } from './app.module';

@Component({
    selector: 'app-root',
    standalone: true,
    templateUrl: './app.component.html',
    styleUrl: './app.component.css',
    imports: [SharedModule, FeatureModule, AppModule, RouterModule]
})
export class AppComponent {
  title = 'Fulbo-Quotes';
}
