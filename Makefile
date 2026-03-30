CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g -O2

TOPIC_SRCS := $(sort $(wildcard topics/*/*.c))
BINARIES := $(addprefix bin/,$(notdir $(TOPIC_SRCS:.c=)))

define BIN_RULE
bin/$(notdir $(basename $(1))): $(1)
	@mkdir -p bin
	$$(CC) $$(CFLAGS) -o $$@ $$<
endef
$(foreach s,$(TOPIC_SRCS),$(eval $(call BIN_RULE,$(s))))

.PHONY: all clean run run-all preview

all: $(BINARIES)

clean:
	rm -rf bin

run:
	@test -n "$(TOPIC)" || (echo "Usage: make run TOPIC=04_loops/for_loop" >&2; exit 1)
	@$(MAKE) bin/$(basename $(TOPIC))
	@./bin/$(basename $(TOPIC))

run-all:
	@chmod +x scripts/run_all.sh
	@./scripts/run_all.sh

preview:
	@chmod +x scripts/generate_previews.sh
	@./scripts/generate_previews.sh
