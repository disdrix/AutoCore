# Review A (reconstruction fidelity): `aa_0044fe10` AnmTrackEvents_UnserializeOneEvent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fe10` |
| **VA** | `0x0044fe10`–`0x0044fe65` (**86 B**) |
| **Canonical name** | `AnmTrackEvents_UnserializeOneEvent_Inferred` |
| **Ghidra name** | `FUN_0044fe10` |
| **Review date** | `2026-07-29` (W36-G dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-G) |
| **Counterpart** | `reviews/B_aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md` |
| **System** | anmTrackEvents per-event unserialize |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 86 B) + `analyze_function_complete` + xrefs + caller/callee decompile |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Unserialize one `anmTrackEvents` event: read FOURCC/key from EDI chunk reader, NestedHash0x10 bag lookup, factory node, store object, call object vtbl[+4] with EDI.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044fe10_FUN_0044fe10.md` (+ W36-G append) |
| Annotated | `docs/reconstruction/raw/aa_0044fe10_FUN_0044fe10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnmTrackEvents_UnserializeOneEvent_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044fe10.cpp` |
| Function | `docs/reconstruction/functions/aa_0044fe10_FUN_0044fe10.md` |
| Named | `docs/reconstruction/functions/aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md` |
| Live | decompile ≡ raw CF; full 86 B hex; 1 caller site |
| Context | W35-E NestedHash once-get; caller `FUN_00987750` product strings |

---

## 3. Signature (sealed)

```c
uint32_t AnmTrackEvents_UnserializeOneEvent_Inferred(void **out_event);
/* EDI = stoChunkReader* register formal */
```

| Slot | Source | Conf |
|---|---|---|
| `out_event` | stack; `MOV [ECX],EAX` | **High** |
| EDI | `MOV ESI,EDI`; `PUSH EDI` before obj vcall | **High** |
| return success | obj vtbl[+4] | **High** |
| return miss | `OR EAX,-1` → `0xffffffff` | **High** |
| cleanup | `ADD ESP,8; RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
key = FUN_0076a900()           // ESI←EDI first
bag = FUN_0044fee0()
FUN_0046c1b0(&key)             // ESI=bag → node out
bag = FUN_0044fee0()
if (node == *(bag+8)) obj = null
else obj = thiscall node[+0xC]
*out_event = obj
if (obj) return thiscall obj[+4]  // PUSH EDI
return 0xffffffff
```

| Stage | Match | Conf |
|---|---|---|
| EDI→ESI key read | **Yes** | **High** |
| NestedHash once-get ×2 | **Yes** | **High** |
| Sentinel compare bag+8 | **Yes** | **High** |
| Factory / store / vcall+4 | **Yes** | **High** |
| Caller product plate | **Yes** (`anmTrackEvents.cpp`) | **High** |
| Event class English | open | **Low** |

---

## 5. Gaps / open

1. Product C++ type of factory node / event object.
2. Whether decompiler's factory `(uVar1)` arg is real (bytes: no key PUSH before `FF 51 0C`).
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI/CF/NestedHash/anmTrackEvents role sealed; residual product class names only.
