#include <bits/stdc++.h>
#include <cairo/cairo.h>
#define CAIRO_HAS_PNG_FUNCTIONS 1

int main()
{
  cairo_surface_t *scaleSF = cairo_image_surface_create_from_png ("1.png");


  cairo_t *context = cairo_create (scaleSF);
  cairo_scale(context, 0.5f, 0.5f);
  cairo_set_source_surface(context, scaleSF, 0,0);
  cairo_pattern_set_extend (cairo_get_source(context), CAIRO_EXTEND_NONE);
  cairo_set_operator (context, CAIRO_OPERATOR_SOURCE);
  cairo_paint(context);
  cairo_surface_t *scaledSF = cairo_surface_create_similar(scaleSF, 
                                          cairo_surface_get_content (scaleSF), 
                                          static_cast<int>(cairo_image_surface_get_width(scaleSF)*0.5f), 
                                          static_cast<int>(cairo_image_surface_get_height(scaleSF)*0.5f));
  cairo_t *contextScaled = cairo_create(scaledSF);
  cairo_set_source_surface(contextScaled, scaleSF, 0,0);
  cairo_paint(contextScaled);

  cairo_status_t cairoStatus = cairo_surface_write_to_png (scaledSF, "scaled.png");
  if(cairoStatus) std::cout << "shit\n";
  cairo_destroy(context);
  return 0;
}
