# Review A (reconstruction fidelity): `aa_005e1fc0` Object_FwriteColorFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1fc0` |
| **VA** | `0x005e1fc0`–`0x005e203c` (124 B / `0x7C`) |
| **Canonical name** | `Object_FwriteColorFields_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_005e1fc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W29-J) |
| **Counterpart** | `reviews/B_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` |
| **System** | object stream serialize (color extension) |
| **Verdict** | **accept-with-gaps** — CF + thiscall/ret4 + field offsets + pack/fwrite order sealed; class English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `get_function_by_address` + `read_memory` + callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Serialize extension method on a game object:

1. Base `thunk_FUN_005a61d0(this, FILE*)` dumps shared header fields.
2. Write `this+0x170` (4 B raw).
3. Pack `this+0x174` float4 → u8×4; pack `this+0x184` float4 → u8×4 via `FUN_00973820`.
4. `fwrite` both packed colors to the same FILE stream.

Paired with deserialize `FUN_005e2040` (vtable neighbor) which reads the same layout.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x005e1fc0` (2026-07-29 ≡ raw 2026-07-23 CF) |
| Bounds | `get_function_by_address` → `005e1fc0`–`005e203c` |
| Entry/exit bytes | `read_memory` 128 B; epilogue `C2 04 00`; pad `CC` |
| Callees | `thunk_FUN_005a61d0`, `fwrite` @ IAT `0x009c64bc`, `FUN_00973820` ×2 |
| Data xref | vtable `@ 0x009dc8e8` |
| Twin peek | `FUN_005e2040` decompile (read path; not OWN) |
| Pack sibling | W28-E `Color_PackFloat4_Scale255_Inferred` |

**Not performed:** Launcher, runtime stream golden, product rename in Ghidra.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `005e1fc0`–`005e203c` (124 B) | **Confirmed** | bounds + `ret 4` + `CC` pad |
| **`__thiscall`** + stack `FILE*` + **`ret 4`** | **Confirmed** | `mov esi,ecx`; epilogue `C2 04 00` |
| Base call then raw `+0x170` then two packs | **Confirmed** | decompile + callees + offsets in lea |
| Pack src `+0x174` / `+0x184`; dest stack locals | **Confirmed** | `lea ecx,[esi+…]` push; `lea ecx,[esp+…]` call |
| Final fwrites are **packed colors**, not FILE* | **Confirmed** | bytes; decompiler **rejected** on locals |
| Code callers | **Confirmed none** | only DATA vtable |
| Product class name | **Open** | |
| `+0x170` semantic | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| `sub esp,8`; save ebx/esi/edi | Yes |
| ECX → ESI (this); stack arg → EDI (FILE*) | Yes |
| `call thunk_FUN_005a61d0` | Yes |
| `fwrite(this+0x170, 4, 1, file)` via IAT ebx | Yes |
| Pack float4 @ `+0x174` (`FUN_00973820`) | Yes |
| Pack float4 @ `+0x184` | Yes |
| `fwrite` packed A; `fwrite` packed B | Yes |
| restore; `add esp,8`; **`ret 4`** | Yes |

---

## 5. Gaps

1. Retail / PDB symbol and owning class for vtable `0x009dc8e8`.
2. Meaning of raw dword `+0x170`.
3. Color channel roles for the two float4 slots.
4. Runtime / differential stream capture.

**Verdict:** **accept-with-gaps** — serialize color-extension CF and ABI sealed; product English open.
