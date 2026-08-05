# Review A (reconstruction fidelity): `aa_00971640` AssPreloader_EnqueueEligibleFromRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971640` |
| **VA** | `0x00971640`–`0x009716f7` (**184 B**) |
| **Canonical name** | `AssPreloader_EnqueueEligibleFromRing_Inferred` |
| **Ghidra name** | `FUN_00971640` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-K) |
| **Counterpart** | `reviews/B_aa_00971640_AssPreloader_EnqueueEligibleFromRing_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 184 B) + `analyze_function_complete` + caller sites `00971700`/`a0`/`820` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk a caller-owned GuardedVector ring of asset keys and enqueue eligible keys into AssPreloader pending (`host+0x1c`), signaling `SetEvent(host+4)` when any key was added.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971640_FUN_00971640.md` (+ W31-K append) |
| Annotated | `docs/reconstruction/raw/aa_00971640_FUN_00971640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_EnqueueEligibleFromRing_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971640.cpp` |
| Function record | `docs/reconstruction/functions/aa_00971640_FUN_00971640.md` |
| Named record | `docs/reconstruction/functions/aa_00971640_AssPreloader_EnqueueEligibleFromRing_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; RET 4; ESI formal from callers |

---

## 3. Signature (sealed)

```c
// ESI=source ring; stdcall 1 (host*); RET 4; void
void AssPreloader_EnqueueEligibleFromRing_Inferred(
    void* host /*stack*/,
    GuardedVectorHeader* source /*ESI*/);
```

| Slot | Source | Conf |
|---|---|---|
| source ring | **ESI** (`mov edi,[esi+0xc]`; callers lea/mov esi→local) | **High** |
| host | Stack after ret (`mov ebp,[esp+0x18]`) | **High** |
| cleanup | **`RET 4`** | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
dirty=0
for idx in [begin, begin+size):
  key* = slot(source, idx)
  it = lower_bound(host+0x10, key)     // FUN_0043d5e0
  if it != end(host+0x14): continue
  node = cache_lookup(host->cache@+0x110, key)  // FUN_0044e8c0
  if node != cache_end && node->field0c != 0: continue
  if Contains(host+0x1c, key*): continue       // FUN_0043e5b0
  dirty=1; Push(host+0x1c, *key)               // FUN_0043e4b0
if dirty: SetEvent(*(HANDLE*)(host+4))
```

| Stage | Match | Conf |
|---|---|---|
| Ring page wrap math | **Yes** | **High** |
| Tree absent gate (+0x10/+0x14) | **Yes** | **High** |
| Cache unloaded gate (+0x110) | **Yes** | **High** |
| Pending contains+push (+0x1c) | **Yes** | **High** |
| SetEvent on dirty | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry / ESI + host:

```
83 EC 10          ; sub esp, 0x10
55                ; push ebp
8B 6C 24 18       ; mov ebp, [esp+0x18]  ; host
57                ; push edi
8B 7E 0C          ; mov edi, [esi+0x0c]  ; source.begin
```

Epilogue:

```
8B 45 04          ; mov eax, [ebp+4]
50                ; push eax
FF 15 8C 61 9C 00 ; call [SetEvent]
5F 5D 83 C4 10 C2 04 00  ; pop edi/ebp; add esp,10; ret 4
```

Body length **184 B**. Full hex in raw W31-K append.

---

## 6. Gaps

- Product/PDB method English (family sealed via sibling `assPreloader.cpp` string on `FUN_00971480`).
- Nested `FUN_0043d5e0` / `FUN_0043e4b0` / cache node field product labels (not owned).
- Runtime / bit-exact / differential.

---

## 7. Verdict

Fidelity pass seals ABI, ring walk, three-gate enqueue, event signal. Product method English + nested dual residual → **accept-with-gaps**.
