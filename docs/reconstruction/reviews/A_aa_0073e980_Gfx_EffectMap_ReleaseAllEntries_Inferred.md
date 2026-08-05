# Review A (reconstruction fidelity): `aa_0073e980` Gfx_EffectMap_ReleaseAllEntries_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073e980` |
| **VA** | `0x0073e980`–`0x0073e9af` exclusive (**47 B** / `0x2F`) |
| **Canonical name** | `Gfx_EffectMap_ReleaseAllEntries_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0073e980` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-W) |
| **Counterpart** | `reviews/B_aa_0073e980_Gfx_EffectMap_ReleaseAllEntries_Inferred.md` |
| **System** | Palantir graphics — global effect tree release (device-reset shutdown) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (47 B full) + `analyze_function_complete` + callers/xrefs + callee decompile `FUN_0073e780` / `FUN_004425f0` + caller site in `FUN_0075eff0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

For-each over global tree **`DAT_00d1ee68`**: release each node payload at **`+0xC`** via **`FUN_0073e780`**, advance with tree **iterator++** (`FUN_004425f0`, **`EDX=&cur`**, isnil@`+0x11`). Used in **`GfxDevice_Reset`** shutdown before lost-device helpers. Does **not** erase map nodes.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-W append) | `docs/reconstruction/raw/aa_0073e980_FUN_0073e980.md` |
| Annotated | `docs/reconstruction/raw/aa_0073e980_FUN_0073e980.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_EffectMap_ReleaseAllEntries_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073e980.cpp` |
| Function record | `docs/reconstruction/functions/aa_0073e980_FUN_0073e980.md` |
| Named record | `docs/reconstruction/functions/aa_0073e980_Gfx_EffectMap_ReleaseAllEntries_Inferred.md` |
| Live | decompile CF ≡ scaffold; full 47 B hex; `C3` plain RET |
| Payload callee | `FUN_0073e780` — vector Release loop + freelist + clear `+0x10` |
| Iterator | `FUN_004425f0` — MSVC tree successor, isnil@`+0x11` |
| Parent | W37-N `GfxDevice_Reset` call @ `0x0075f145` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
void Gfx_EffectMap_ReleaseAllEntries_Inferred(void);  // plain RET
```

| Slot | Source | Conf |
|---|---|---|
| head | `MOV ESI,[DAT_00d1ee68]` | **High** |
| begin | `MOV EAX,[ESI]`; stack `cur` @ `[ESP+4]` | **High** |
| payload | `[cur+0xC]` → `PUSH` / `FUN_0073e780` | **High** |
| advance | `LEA EDX,[ESP+4]`; `FUN_004425f0` | **High** |
| cleanup | `POP ESI; POP ECX; RET` (`C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
head = DAT_00d1ee68; cur = *head
if cur == head: return
loop:
  FUN_0073e780(cur[+0xC])
  iterator++(&cur)   // FUN_004425f0
  if cur != head: goto loop
return
```

---

## 5. Machine bytes

- Body **47 B**; pad `CC` @ `0x0073e9af`.
- Full hex in raw W38-W append.
- Call targets sealed: `FUN_0073e780`, `FUN_004425f0`.

---

## 6. Gaps (fidelity)

- Product English for map / value_type.
- Unowned duals: `FUN_0073e780`, insert/erase, `DAT_00d1ee64` map object.
- Runtime / bit-exact / differential.

---

## 7. Verdict rationale

Body, ABI (void/global), tree walk + payload release + iterator++ sealed against full hex and sole `GfxDevice_Reset` caller. Structural `_Inferred` name only. Residual product English does not block **accept**.
