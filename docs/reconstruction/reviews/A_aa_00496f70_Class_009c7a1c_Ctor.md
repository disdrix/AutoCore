# Review A (reconstruction fidelity): `aa_00496f70` Class_009c7a1c_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00496f70` |
| **VA** | `0x00496f70`–`0x004970a8` exclusive (**312 B** / `0x138`) |
| **Canonical name** | `Class_009c7a1c_Ctor` |
| **Ghidra name** | `FUN_00496f70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-G) |
| **Counterpart** | `reviews/B_aa_00496f70_Class_009c7a1c_Ctor.md` |
| **System** | class / complete-object constructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **complete-object constructor** for vtbl family `PTR_FUN_009c7a1c`:

1. Install vtbl.
2. Seed `+4/+8 = 0x40`.
3. Allocate StdList sentinel (`FUN_00457c60`) → `this+0x10`; size `this+0x14=0` (list LEA at `+0x0C`).
4. Zero six buffer triples + cookie-vector `@+0x28`.
5. Flags / floats (300.f / 25.f) / copy `ctx+0x7d` / mode dword `3`.
6. Return `this` with **`ret 4`**.

Complete dtor twin: `Class_009c7a1c_CompleteDtor` `0x004970b0` (W28-M). Scalar deleting is **not** this VA.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-G) | `docs/reconstruction/raw/aa_00496f70_FUN_00496f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00496f70_FUN_00496f70.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Class_009c7a1c_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00496f70.cpp` |
| Function records | `functions/aa_00496f70_FUN_00496f70.md`, `functions/aa_00496f70_Class_009c7a1c_Ctor.md` |
| Twin dtor | `Class_009c7a1c_CompleteDtor` W28-M |
| Live | decompile; body bounds; epilogue `C2 04 00`; list LEA; float constants |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; stack context*; returns this; ret 4
void *__thiscall Class_009c7a1c_Ctor(void *self, void *ctx);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| ctx | stack (`ret 4`) | **High** |
| return | EAX = this | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH LAB_009a0d1e
*this = PTR_FUN_009c7a1c
+4=+8=0x40
LEA list=this+0x0C; head=FUN_00457c60(); list.head=+0x10; list.size=0
zero triples {0x1C,0x30,0x40} + vector@+0x28
flags + movss 300.f/+0x54 + 25.f/+0x58 + ctx[0x7d]
zero mid + remaining triples {0x9C,0xAC,0xBC}
return this; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl + 0x40 pair | **Yes** | **High** |
| List sentinel factory | **Yes** | **High** |
| Six buffer zeros match dtor free set | **Yes** | **High** |
| Float constants 300/25 | **Yes** (bytes) | **High** |
| Sole factory caller / size 0xC8 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `6A FF 68 1E 0D 9A 00` … `8B F1` … `C7 06 1C 7A 9C 00` |
| List | `8D 7E 0C` … `E8 …` → `00457c60`; `89 47 04` / `89 47 08` |
| Floats | `F3 0F 10 05 A8 A8 AA 00` / `FC A6 AA 00` |
| Epilogue | `C2 04 00` |
| Size | **312 B** exclusive end `0x004970a8` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangled class name.
- Semantic labels for 0x40 pair, mode=3, float fields, buffer payloads.
- First dword of list object (`this+0x0C`) not written.
- Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, vtbl, list seed, buffer zeros, floats sealed → **accept-with-gaps** (product English residual).
