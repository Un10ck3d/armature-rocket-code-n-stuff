from django.contrib import admin

from rocketinterface.rsocket.models import Flight, Rocket

# Register your models here.
admin.site.register(Flight)
admin.site.register(Rocket)