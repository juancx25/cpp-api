import { NgModule } from "@angular/core";
import { FeatureModule } from "./feature/feature.module";
import { SharedModule } from "./shared/shared.module";
import { CommonModule } from "@angular/common";
import { HttpClientModule } from "@angular/common/http";

@NgModule({
    declarations: [
    ],
    imports: [
      FeatureModule,
      SharedModule,
      CommonModule,
      HttpClientModule
    ],
    providers: [
    ]
  })
  export class AppModule { }