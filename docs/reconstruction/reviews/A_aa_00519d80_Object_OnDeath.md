# Review A (reconstruction fidelity): `aa_00519d80` Object_OnDeath

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519d80` |
| **VA** | `0x00519d80`–`0x0051a0db` exclusive end `0x0051a0dc` (**860 B** / `0x35C`) |
| **Canonical name** | `Object_OnDeath` |
| **Ghidra name** | `FUN_00519d80` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9R-G) |
| **Counterpart** | `reviews/B_aa_00519d80_Object_OnDeath.md` |
| **System** | object lifecycle / combat death |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Multi-class **object OnDeath** virtual method:

1. Resolve owner TFID @ `this+0x40`; optional detach via `FUN_004cdc80` when host vfunc `+0x210` disagrees.
2. Optional `FUN_004d2700` when packed mask @ `+0x28/+0x2C` valid and stack deathCtx non-zero; resolve self COID TFID @ `+0x160`.
3. Stamp `this+0x1C = DAT_00b0421c`; clear net mask bit 8 on iface @ `+0x14`.
4. Notify owner chain (vfuncs `+0x228/+0x224/+0x54`) and optional double-list remove @ flag `+0x23`.
5. Vfunc `+0x40(1)`; optional `FUN_005b2ba0` if `this+0x64`.
6. Branch on localish vfunc `+0x198` / global flag `+0x168` / clone type @ `clone+0x38` ∈ {1,3}:
   - **Death-complete path:** optional HB (`new 0x24` + `FUN_005dabc0` + Enqueue `world+0xe4ec` + Start) when flag bit12 @ `+0x17c` set and `world+0x7e`; vfunc `+0x2a8`; `FUN_004e77d0(..., mode 0|1)`; set `*(byte*)(this+0x17d)|=1`; return 0.
   - **Delete-queue path:** set same death flag bit; if InactiveObjects hash still holds COID → product **ONDeath** log + `FUN_004bcda0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9R-G append) | `docs/reconstruction/raw/aa_00519d80_FUN_00519d80.md` |
| Annotated | `docs/reconstruction/raw/aa_00519d80_FUN_00519d80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_OnDeath.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00519d80.cpp` |
| Live | decompile ≡ raw CF; entry SEH+`8B F1`; epilogue `C2 04 00` |
| String | `ONDeath` + `InactiveObjectsHas` (High) |
| Vtbl DATA | `009ce29c`, `009d3414`, `009d419c`, `009dbc4c` → `0x00519d80` |
| Callers | `FUN_0053cf70`, `FUN_00582670` (death FX then this) |
| Peer | `Object_QueueDelete` `0x004d4790` (same warn family, narrower body) |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; stack deathCtx; ret 4
uint32_t __fastcall Object_OnDeath(void *self, int /*edx*/, int deathCtx);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| deathCtx | stack; `ret 4`; decompiler `unaff_retaddr` | **High** (presence) / **Probable** (English) |
| return | 0 on `FUN_004e77d0` path; status byte on delete path | **Probable** (late decompiler return garbled) |

---

## 4. Control flow fidelity

| Stage | Match | Conf |
|---|---|---|
| SEH + this in ESI | **Yes** | **High** |
| TFID resolve + host compare + `004cdc80` | **Yes** | **High** |
| Net mask bit 8 clear | **Yes** | **High** |
| Type 1/3 gate + flag bit12 | **Yes** | **High** |
| HB new(0x24)/Enqueue/Start | **Yes** | **High** |
| `FUN_004e77d0` modes 0/1 | **Yes** | **High** |
| Death flag `+0x17d \|= 1` both paths | **Yes** | **High** |
| ONDeath InactiveObjects warn | **Yes** | **High** |
| Float scale `DAT_009cec58` ≈0.001831f | **Yes** (bytes) | **High** |
| Product demangle / class plate | open | — |

**Clean ≡ raw CF order.** Decompiler register artifacts (`unaff_*`, `_DAT_00000000` list head) do not change sealed CF.

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `64 A1 … 6A FF 68 BA 36 9A 00 50 64 89 25 … 83 EC 08 53 56 8B F1` |
| Epilogue | `64 89 0D 00 00 00 00 83 C4 14 C2 04 00` + `CC` |
| Size | **860 B** exclusive end `0x0051a0dc` |
| Float | `009cec58` = `F0 00 F0 3A` |

**No `disassemble_bytes` used.**

---

## 6. Confidence table

| Claim | Level |
|---|---|
| OnDeath role (string + CF) | **High** |
| ABI thiscall + ret 4 | **High** |
| Multi-vtbl method | **High** |
| Delete-queue / InactiveObjects path | **High** |
| deathCtx product English | **Tentative** |
| Full vfunc English (+0x210/+0x2a8/…) | **Tentative** |
| Runtime / bit-exact | **Open** |

---

## 7. Verdict

**accept-with-gaps** — CF, ABI, string role, multi-vtbl, flag/HB/delete-queue paths sealed; product demangle and deathCtx English open.
