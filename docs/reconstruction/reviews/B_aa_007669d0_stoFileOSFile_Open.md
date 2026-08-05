# Review B (skeptical / adversarial): `aa_007669d0` stoFileOSFile_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007669d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-E) |
| **Counterpart** | `reviews/A_aa_007669d0_stoFileOSFile_Open.md` |
| **Scratch** | `tmp/a_007669d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | CRT `fopen` is the actual open (not CreateFile) | **Falsified** — fopen only for existence probe; real open is `CreateFileA` |
| 2 | Mode 6 is read | **Falsified** — access `0x20006` + `CREATE_ALWAYS`; callers use mode 6 for write (`FUN_00984d30`) |
| 3 | Mode 1 is write | **Falsified** — access `0x20001`; callers use mode 1 for read |
| 4 | Bare `C3` / `RET 4` | **Falsified** — dual `C2 0C 00` (3 stack args) |
| 5 | Always remaps paths | **Falsified** — gated on `FUN_007a69d0()->+0x2c != 0` and `.ogg`/`.dds` only |
| 6 | Returns HANDLE in EAX | **Falsified** — returns 0/-1; HANDLE stored at `this+8` |
| 7 | Class is generic FileStream not stoFileOSFile | **Falsified** — log path `…\stoFileOSFile.cpp` sealed |
| 8 | Modes 4/5 are valid special cases | **Weakened** — jump table lands with access still 0; CreateFile fails → -1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CreateFile mode matrix | **High** | Wrong open flags in port |
| RET 0x0C + 0/-1 | **High** | Stack/ABI bugs |
| this+4 mode / this+8 HANDLE | **High** | Layout bugs |
| Quality remap existence | **High** | Missing locale/quality assets |
| Exact quality tag mapping 1/2/3 | **High** (bytes + constants) | Wrong suffix |
| 5th DDS table entry | **Med** | Edge path miss |
| Method demangle | **Med** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Call-site evidence (prior duals + this wave xrefs):
//   FUN_009841d0 / FUN_00984910: Open(path, mode=1, flags=0)  // read
//   FUN_00984d30:                Open(path, mode=6, flags=0)  // write/create
//
// Access constants:
//   0x20001 = READ_CONTROL | FILE_READ_DATA
//   0x20006 = READ_CONTROL | FILE_WRITE_DATA | FILE_APPEND_DATA
//   0x20007 = READ_CONTROL | FILE_READ_DATA | FILE_WRITE_DATA | FILE_APPEND_DATA
//
// Disposition: default OPEN_EXISTING(3); mode 6 → CREATE_ALWAYS(2) fallthrough to write access
// Share: always 1 (FILE_SHARE_READ)
```

Live decompile ≡ scaffold CF for open path. Dual RET 0x0C sealed. Quality tags `_FR/_DE/_UK` and extensions `.ogg`/`.dds` sealed by `read_memory`. Rejects “fopen is the open” and “returns HANDLE”.

---

## 4. Surviving contract for AutoCore

```
// Port:
int Open(stoFileOSFile* self, const char* path, uint32_t mode, DWORD attrs) {
  self->mode = mode;
  path = MaybeQualityRemap(path); // .ogg/.dds when quality!=0; fopen probe
  // map mode → (access, disposition) as matrix above
  self->handle = CreateFileA(path, access, FILE_SHARE_READ, NULL, disp, attrs, NULL);
  if (self->handle != INVALID_HANDLE_VALUE) return 0;
  LogOpenError(path); // stoFileOSFile.cpp:0xB9
  return -1;
}
// ABI: thiscall; RET 0x0C; do not treat EAX as HANDLE.
// Mode 0 and 4/5 are fail paths.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/mode matrix/HANDLE layout/log plate and rejects fopen-as-open / HANDLE-return / mode-role inversions. Residual method demangle + quality singleton + 5th DDS entry → **accept-with-gaps**.
