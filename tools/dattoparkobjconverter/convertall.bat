@echo OFF
title "Converting DAT --> parkobj (optimized)"
echo "Start conversion DAT --> parkobj (optimized)"

echo "Rides:"
title "Converting Rides (Dat --> parkobj (optimized))"
for /r %%i in (DAT\Rides\*) do objexport %%i parkobj\Rides\ -z

echo "Paths:"
title "Converting Paths (Dat --> parkobj (optimized))"
for /r %%i in (DAT\Paths\*) do objexport %%i parkobj\Paths\ --split -z

echo "Scenery:"
title "Converting Scenery (Dat --> parkobj (optimized))"
for /r %%i in (DAT\Scenery\*) do objexport %%i parkobj\Scenery -z

echo "Themes:"
title "Converting Themes (Dat --> parkobj (optimized))"
for /r %%i in (DAT\Themes\*) do objexport %%i parkobj\Themes -z

echo "Done converting..."
title "Finshed conversion (Dat --> parkobj (optimized))"
pause