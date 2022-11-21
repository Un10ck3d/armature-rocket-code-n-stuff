from django.db import models

# Create your models here.
class Rocket(models.Model):
    name = models.CharField(max_length=30)
    image = models.ImageField(upload_to='static', blank=True)

    class Meta():
        verbose_name = "rocket"
        verbose_name_plural = "rockets"

    def __str__(self):
        return self.name

class Flight(models.Model):
    rocket = models.ForeignKey(Rocket, on_delete=models.CASCADE)
    name = models.CharField(max_length=30)

    class Meta():
        verbose_name = "flight"
        verbose_name_plural = "flights"

    def __str__(self):
        return "Flight " + str(self.id) + " - " + self.rocket.name  # type: ignore