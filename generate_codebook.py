import os

OUTPUT = "generated_content.tex"

def list_cpp_files_by_folder(base_dir="."):
    sections = {}
    for root, dirs, files in os.walk(base_dir):
        if root == ".":
            continue  # skip root
        cpp_files = [f for f in files if f.endswith(".cpp")]
        if cpp_files:
            section_name = os.path.basename(root)
            sections[section_name] = [
                os.path.join(root, f) for f in sorted(cpp_files)
            ]
    return sections

sections = list_cpp_files_by_folder()

with open(OUTPUT, "w") as out:
    for section, files in sorted(sections.items()):
        out.write(f"\\section*{{{section}}}\n")
        for file in files:
            shortname = os.path.basename(file)
            out.write(f"\\subsection*{{{shortname}}}\n")
            out.write(f"\\lstinputlisting{{{file}}}\n\n")
