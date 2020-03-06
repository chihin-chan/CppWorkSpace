.PHONY: clean All

All:
	@echo "----------Building project:[ test2_2019 - Debug ]----------"
	@cd "test2_2019" && "$(MAKE)" -f  "test2_2019.mk"
clean:
	@echo "----------Cleaning project:[ test2_2019 - Debug ]----------"
	@cd "test2_2019" && "$(MAKE)" -f  "test2_2019.mk" clean
