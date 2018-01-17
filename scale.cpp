#include <bits/stdc++.h>
#include <cairo/cairo.h>
#define CAIRO_HAS_PNG_FUNCTIONS 1

int main()
{
  cairo_surface_t *source = cairo_image_surface_create_from_png ("1.png");
  cairo_surface_t *dest = cairo_surface_create_similar(source, cairo_surface_get_content(source), cairo_image_surface_get_width(source) / 2, cairo_image_surface_get_height(source) / 2);


  cairo_t *context = cairo_create(dest);
  cairo_scale(context, 0.5f, 0.5f);
  cairo_set_source_surface(context, source, 0 , 0);
//  cairo_pattern_set_extend (cairo_get_source(context), CAIRO_EXTEND_NONE);
//  cairo_set_operator (context, CAIRO_OPERATOR_SOURCE);  
//cairo_pattern_set_filter(cairo_get_source(context), CAIRO_FILTER_NEAREST);
  cairo_paint(context);

  cairo_status_t cairoStatus = cairo_surface_write_to_png (dest, "scaled.png");
  if(cairoStatus) std::cout << "shit\n";
  cairo_destroy(context);
  return 0;
}
