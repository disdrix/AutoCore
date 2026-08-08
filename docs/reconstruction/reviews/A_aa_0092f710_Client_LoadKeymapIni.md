# Review A (reconstruction fidelity): `aa_0092f710` Client_LoadKeymapIni

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f710` |
| **VA** | `0x0092f710`–`0x0092f91a` |
| **Canonical name (Ghidra)** | `FUN_0092f710` |
| **Proposed name** | `Client_LoadKeymapIni` |
| **Review date** | `2026-08-05` (MEGA-022 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0092f710_Client_LoadKeymapIni.md` |
| **System** | input-drive-control |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client boot-time **keymap.ini loader**:

1. `fopen("keymap.ini","r")`.
2. On fail: write default keymap via `FUN_007f9480` (path `"keymap.ini"` in EAX, ActionMap `client+0x116c` on stack) and `RET 4`.
3. On success: for each line — strip `//` comments, tokenize on `=;`, require description length ≥ 2, scan modes 0..3 for a matching ActionMap description (`FUN_007f9230`), copy primary/alt key strings, parse tokens (`FUN_0092db30`), apply binds with dualed `ActionMap_TrySetSlotBind` **primary lane BL=0 then alt lane BL=1**.
4. `fclose` and `RET 4`.

Sole caller: dualed **`Client_InitInstance`** (`0x0094a6a0`) in the Ini/Keymap boot plate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0092f710` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/locals) |
| Assembly | `disassemble_function` (full body; **not** `disassemble_bytes`) |
| Bytes | `read_memory` entry + epilogue + DAT delimiters + `"keymap.ini"` |
| Callers / xrefs | `get_function_callers` (1) + `get_function_xrefs` (1 UNCONDITIONAL_CALL @ `0x0094a83b`) |
| Call-site context | `Client_InitInstance` decompile (plate `Ini, Keymap, colors`) |
| Peer duals | `ActionMap_TrySetSlotBind` A/B; `Client_InitInstance` record |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0092f710` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers.

---

## 3. Signature

```c
void Client_LoadKeymapIni(void* client /* stack0 */);
// void; RET 4; ActionMap at client+0x116c
```

| Item | Evidence |
|---|---|
| Stack formal | fail path `MOV EAX,[ESP+0xc20]`; call site `FUN_0092f710(param_1)` |
| Frame | `SUB ESP,0xc18` |
| Epilogue | `ADD ESP,0xc18` + `RET 4` @ `0x0092f752` and `0x0092f918` |
| Body size | 523 B (`0x20B`); pad `CC` before next code |
| Path on fail | `MOV EAX,0x00a2e624` then `CALL FUN_007f9480` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| fopen keymap.ini / r | **Yes** | **High** |
| Fail → write default + RET 4 | **Yes** (asm path-in-EAX sealed) | **High** |
| Load `//` and `=;` delimiters | **Yes** (`read_memory`) | **High** |
| fgets loop / EOF fclose | **Yes** | **High** |
| Comment strip via strstr | **Yes** | **High** |
| strtok description; strlen≥2 | **Yes** (asm CMP 2 / JC) | **High** |
| Mode scan 0..3 + find-slot | **Yes** | **High** |
| Primary + optional alt strncpy | **Yes** | **High** |
| Parse + TrySetSlotBind BL=0 then BL=1 | **Yes** (asm; decomp lost BL) | **High** |
| Sole InitInstance caller | **Yes** | **High** |

### Layout / constants

| Addr / off | Role |
|---|---|
| `client+0x116c` | ActionMap base |
| `0x00a2e624` | `"keymap.ini"` |
| `0x00a152e4` | `"r"` |
| `0x00a152dc` | `"//"` |
| `0x00a152e0` | `"=;"` |
| line buf | 0x800 (`fgets`) |
| primary/alt | 0x200 each; copy cap `0x1ff` |

### Call-site sample

| Site | Context |
|---|---|
| `Client_InitInstance` @ `0x0094a83b` | After `FUN_0092f960()`, before `FUN_0092f580()`; plate Keymap |

---

## 5. Gaps

1. Product English for mode groups 0..3 (counts/offsets sealed via dualed `ActionMap_TrySetSlotBind`).
2. Full dual seal of `FUN_007f9230` / `FUN_007f9480` / `FUN_0092db30` (used as sealed callees only).
3. Exact C type of ActionMap blob at `+0x116c`.
4. Runtime / bit-exact / differential.

## Verdict rationale

CF, ABI (`RET 4`), product path string, delimiter constants, dual-lane bind apply, and sole InitInstance caller are **High**. Residual is helper dual depth + mode English + runtime → **accept-with-gaps** (not reject: no CF/ABI conflict).
