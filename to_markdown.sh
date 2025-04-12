#!/bin/bash

output_file="all_solutions.md"
> "$output_file"  # Clear the file if it exists

for dir in */; do
    # Skip the build folder
    if [[ "$dir" == "build/" ]]; then
        continue
    fi

    cpp_file=$(find "$dir" -maxdepth 1 -name "*.cpp")

    if [[ -f $cpp_file ]]; then
        # Get filename without extension
        filename=$(basename "$cpp_file" .cpp)

        # Convert to title: pascals_triangle → Pascals Triangle
        title=${filename//_/ }
        title=$(echo "$title" | sed 's/\b\(.\)/\u\1/g')

        # Append to markdown
        echo "# $title" >> "$output_file"
        echo "" >> "$output_file"
        echo '```cpp' >> "$output_file"
        cat "$cpp_file" >> "$output_file"
        echo '```' >> "$output_file"
        echo "" >> "$output_file"
    fi
done

echo "✅ Markdown file created: $output_file"
