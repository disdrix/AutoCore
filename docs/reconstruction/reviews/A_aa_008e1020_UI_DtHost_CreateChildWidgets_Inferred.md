# Review A (reconstruction fidelity): `aa_008e1020` UI_DtHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e1020` |
| **VA** | `0x008e1020`–`0x008e17be` inclusive (**1951 B** / `0x79F`) |
| **Canonical name** | `UI_DtHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_008e1020` |
| **Review date** | `2026-08-05` (R13-014 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R13-014) |
| **Counterpart** | `reviews/B_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer — dt 2d host CreateChildWidgets* |
| **Evidence pass** | Live Ghidra `decompile_function` (FAILED) + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile (fail) + analyze + read_memory + disassemble_function + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Virtual **CreateChildWidgets** for the dt / disciplines-tree 2d host UI: after residual host prep (`FUN_00792600`), allocate/skin/attach the full `i_d_dt_2d_*` chrome tree (backgrounds, frames, title/icon/cover, instructions, close button, crafting + disciplines tabs), optionally apply a global string path via `DAT_00d1b8a8`, and fire host `vtbl+0x448` / `vtbl+0x34c`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R13-014 append) | `docs/reconstruction/raw/aa_008e1020_FUN_008e1020.md` |
| Annotated | `docs/reconstruction/raw/aa_008e1020_FUN_008e1020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_DtHost_CreateChildWidgets_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e1020.cpp` |
| Function record | `docs/reconstruction/functions/aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md` |
| Live | full disasm (~entry→RET); entry/exit/vtbl hex; XML `.rdata` strings; DATA `0x00a3c3a0` |

---

## 3. Signature (sealed)

```c
// ECX = dt/UI host*; no stack args; void; RET 0
void __thiscall UI_DtHost_CreateChildWidgets_Inferred(void *host);
```

| Formal | Source | Conf |
|---|---|---|
| host | **ECX** (`MOV EBP,ECX` @ `0x008e103c`) | **High** |
| return | void (no EAX contract; `RET`/`C3`) | **High** |
| cleanup | **`RET`** (`C3`) — not stdcall | **High** |

---

## 4. Control flow (authority)

| Stage | Evidence | Conf |
|---|---|---|
| SEH + thiscall | prologue `6A FF 68 A8 72 9B 00 … 8B E9`; handler `0x009b72a8` | **High** |
| Prep | `CALL 0x00792600` with ECX=host | **High** |
| Child pattern | `new` / ctor / `CALL [vtbl+0xa8]` / `CALL [vtbl+0x28]` / store `[EBP+slot]` | **High** |
| Alpha | `PUSH 0x3f000000; PUSH 1; CALL [vtbl+0xfc]` on most chrome | **High** |
| Z-order bump | `++[EBP+0x68]`; `MOVSS [EBP+0x74],XMM0`; optional `[EBP+0x70]`; `CALL [vtbl+0x3f4](1)` | **High** |
| +0x530 double-store | title @ `0x008e142f` then icon @ `0x008e1496` | **High** |
| icon_cover | `CALL [vtbl+0x404]` with path `0x00a3c578`, arg `-1` | **High** |
| Close btn | `new 0x4CC` + `0079c860`; id `0x9c40` → `+0x504` | **High** |
| Tabs | `new 0x81C` + `008230b0`; crafting `+0x54c` id `0x9c41` BL=0 + `00756c90`; disciplines `+0x550` id `0x9c42` BL=1 | **High** |
| Optional global | `DAT_00d1b8a8` → `vtbl+0x3d8` / `+0x120` / host `+0x114` / `007fca10` | **High** |
| Exit | `5F 5E 5D 5B 64 89 0D … 83 C4 18 C3` | **High** |

---

## 5. Machine bytes (entry / exit)

| Item | Hex / notes |
|---|---|
| Body | `0x008e1020`–`0x008e17be` (**1951 B** / `0x79F`) |
| Entry | `6A FF 68 A8 72 9B 00 64 A1 00 00 00 00 50 64 89 25 00 00 00 00 83 EC 0C 53 55 56 57 8B E9` |
| Exit | `5F 5E 5D 5B 64 89 0D 00 00 00 00 83 C4 18 C3` |
| Vtbl | DATA dword @ `0x00a3c3a0` = `0x008e1020` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (virtual) |
| Callers | none direct CALL; **vtbl DATA** `0x00a3c3a0` |
| Callees | `00792600`, `operator_new`, `007b5dd0`, `00864f20`, `0079c860`, `008230b0`, `00822cb0`, `00756c90`, `007fca10`, vtbls |

---

## 7. Gaps

1. Product demangle for dt host class (no RTTI sealed in-unit).
2. Residual helper English (`00792600`, `008230b0`, `0079c860`, `00864f20`, `007fca10`).
3. Why title is overwritten at `+0x530` (icon wins) — product intent open.
4. Runtime / bit-exact / differential (Terminal false).

---

## 8. Verdict

**accept-with-gaps** — ABI/body/vtbl dispatch/XML family/slot map/tab pair sealed via assembly despite decompiler fail; product class demangle + residual helper English + runtime open.
