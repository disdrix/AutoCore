# Review A (reconstruction fidelity): `aa_0075de80` AssManager_SweepTrackedAssets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075de80` |
| **VA** | `0x0075de80`–`0x0075e2ce` exclusive (**1358 B** / `0x54E`) |
| **Canonical name** | `AssManager_SweepTrackedAssets_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0075de80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-O) |
| **Counterpart** | `reviews/B_aa_0075de80_AssManager_SweepTrackedAssets_Inferred.md` |
| **System** | `assets` / `assManager` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (prologue/epilogue + mode-1 push site) + callers/callees/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

assManager tracked-asset list sweep with three structural modes:

1. **mode 1** — collect keys + asset pointers into stack vectors; optional secondary push via `FUN_0043e9e0` under host CS.
2. **mode 2** — age-purge idle assets (`now - stamp >= ageThreshold` and state `+0x10==0`); single outer pass.
3. **other (e.g. 0)** — hard unload idle assets; rescan while any destroyed.

Logs `assManager.cpp:0x1BB` on timed destroy path.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-O) | `docs/reconstruction/raw/aa_0075de80_FUN_0075de80.md` |
| Annotated | `docs/reconstruction/raw/aa_0075de80_FUN_0075de80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_SweepTrackedAssets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075de80.cpp` |
| Function records | `functions/aa_0075de80_FUN_0075de80.md`, `functions/aa_0075de80_AssManager_SweepTrackedAssets_Inferred.md` |
| Live | decompile ≡ raw 2026-07-23 CF; body bounds 1358 B; `RET 8`; 7 callers / 13 xrefs |
| Related duals | W31-J `FUN_0043e9e0` PushBack Stride2 U32U8 (caller site `0x0075e046`); W31-N `FUN_0043e7f0` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=assManager*; stack mode + ageThreshold; RET 8
void AssManager_SweepTrackedAssets_Inferred(
    void *assManager /*ECX*/, int mode, float ageThreshold);
```

| Formal | Source | Conf |
|---|---|---|
| assManager | ECX (`8B F1` → ESI) | **High** |
| mode | stack `[ebp+8]` / `Stack[0x4]` | **High** |
| ageThreshold | stack float | **High** |
| cleanup | `RET 8` (`C2 08 00`) | **High** |
| return | void | **High** |

Decompiler signature `undefined FUN_0075de80(void)` incomplete — do not trust bare form.

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009b0a03; zero key_vec + asset_vec
now = FUN_0076c330()
outer:
  destroyed = 0
  for node in list(this+8):
    asset = node[3]
    if mode==2 && asset:
      if age ok && asset+0x10==0 (under optional CS):
        optional secondary erase; log L0x1BB; release; null asset
      else next
    // shared:
    if mode==1:
      optional CS push key (0043e9e0); unlink; collect key+asset*
    else:
      if keep: next
      if !asset: erase
      else if unloaded: destroy+erase; destroyed++
  if mode==2 || destroyed<1:
    post-collect remap (0044e8c0…); free vecs; return
  else goto outer
```

| Stage | Match | Conf |
|---|---|---|
| ECX this / RET 8 | **Yes** (bytes) | **High** |
| List @ +8 / secondary @ +0x6c | **Yes** | **High** |
| Mode 1/2/other branches | **Yes** (decompile) | **High** |
| Nested PushBack site | **Yes** (bytes @ `0075e046`) | **High** |
| Product method English | shape only | **Inferred** |

---

## 5. Machine bytes (`read_memory`)

Prologue (64 B head):

```
55 8B EC 83 E4 F8 6A FF 68 03 0A 9B 00 64 A1 00 00 00 00 50 64 89 25 00 00 00 00 83 EC 68 53 56 57 33 FF 8B F1 …
```

Epilogue:

```
… 5B 8B E5 5D C2 08 00 CC
```

Mode-1 push (spot): `8B C7 E8 …` → `FUN_0043e9e0` with **EAX=container** (matches W31-J).

Full 1358 B not inlined; bounds sealed by `get_function_by_address`.

---

## 6. Gaps

1. Product/PDB AssManager method name and mode enum English.
2. Asset static type / vtbl[0] product role (release vs scalar dtor).
3. Exact semantics of `node[4]` keep flag and `FUN_00971a20` probe.
4. Nested free of map/vector helpers (owned elsewhere).
5. Runtime / bit-exact under CS concurrency.
6. Zero product strings beyond path+line on this body.

---

## 7. Verdict

Fidelity pass seals ABI, bounds, mode CF, list/secondary layout, and assManager string site → **accept-with-gaps** (product residual only).
