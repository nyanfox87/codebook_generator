import os
import re

OUTPUT_CONTENT = "generated_content.tex"
OUTPUT_MENU = "contents.tex"

def list_cpp_files_by_folder(base_dir="."):
    sections = {}
    for root, dirs, files in os.walk(base_dir):
        if root == ".":
            continue  # skip project root
        cpp_files = [f for f in files if f.endswith(".cpp") or f.endswith("vimrc")]
        if cpp_files:
            section_name = os.path.basename(root)
            sections[section_name] = [
                os.path.join(root, f) for f in sorted(cpp_files)
            ]
    return sections

def latex_escape(s):
    """
    Escape LaTeX special characters for section/subsection titles.
    """
    replacements = {
        "&": r"\&",
        "%": r"\%",
        "$": r"\$",
        "#": r"\#",
        "{": r"\{",
        "}": r"\}",
        "_": r"\_",
    }
    for k, v in replacements.items():
        s = s.replace(k, v)
    return s

def minted_path_escape(path):
    """
    Escape spaces and special characters for minted file paths.
    Minted needs literal spaces escaped as '\ '.
    """
    path = path.replace("\\", "/")  # always use forward slashes
    path = path.replace(" ", r"\ ")
    path = path.replace("%", r"\%")
    return path

def safe_label(name):
    """
    Generate a LaTeX-safe label from a string.
    """
    label = name.replace(" ", "_")
    label = re.sub(r"[^a-zA-Z0-9_:]", "", label)
    return label

sections = list_cpp_files_by_folder()

# =========================================
#  Generate generated_content.tex for minted
# =========================================
with open(OUTPUT_CONTENT, "w") as out:
    for sec_idx, (section, files) in enumerate(sorted(sections.items())):
        safe_section = latex_escape(section)
        section_label = safe_label(f"sec:{sec_idx}_{section}")
        out.write(f"\\section*{{\\texttt{{{safe_section}}}}} \\label{{{section_label}}}\n")

        for file_idx, file in enumerate(files):
            short = os.path.basename(file)
            safe_short = latex_escape(short)
            file_label = safe_label(f"{section_label}_file{file_idx}")
            safe_path = minted_path_escape(file)

            out.write(f"\\subsection*{{\\texttt{{{safe_short}}}}} \\label{{{file_label}}}\n")
            out.write(f"\\inputminted[fontsize=\\footnotesize, linenos, breaklines]{{cpp}}{{{safe_path}}}\n\n")

# =========================================
#  Generate contents.tex (menu) with dotted page numbers
# =========================================
with open(OUTPUT_MENU, "w") as out:
    for sec_idx, (section, files) in enumerate(sorted(sections.items())):
        section_label = safe_label(f"sec:{sec_idx}_{section}")
        safe_section = latex_escape(section)
        out.write(f"\\textbf{{\\Large {safe_section}}} \\dotfill \\pageref{{{section_label}}}\\\\\n")

        for file_idx, file in enumerate(files):
            short = os.path.basename(file)
            safe_short = latex_escape(short)
            file_label = safe_label(f"{section_label}_file{file_idx}")
            out.write(f"{safe_short} \\dotfill \\pageref{{{file_label}}}\\\\\n")

        out.write("\\vspace{0.7em}\n")  # space between sections


print("Generated: contents.tex + generated_content.tex with page references")
