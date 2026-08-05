# Review A (reconstruction fidelity): `aa_007a6de0` StringPool_ApplyModeAndRingStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6de0` |
| **VA** | `0x007a6de0`–`0x007a70d0` (body; `ret 8`) |
| **Canonical name** | `StringPool_ApplyModeAndRingStore_Inferred` (Ghidra `FUN_007a6de0`) |
| **Plate alias** | `Named_CalleeOf_Client_RecvDestroyObject_007a6de0` (weak parent-seed; **do not** use as product role) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction fidelity (clean ≡ raw ≡ live CF) |
| **Counterpart** | `reviews/B_aa_007a6de0_StringPool_ApplyModeAndRingStore_Inferred.md` |
| **System** | client UI / string temp-pool (cross-cutting: auth, inventory, mission, skill toasts) |
| **Evidence pass** | Live `decompile_function` @ `0x007a6de0`; `read_memory` prolog/epilog + `DAT_00a32460` / `DAT_00a96fa0` / `DAT_00a96f9c` / `DAT_00a800e4`; callees listed only (OWN VA) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mode-gated string transform into a 10-slot rotating temp buffer** on a string-pool object (`this`), then return the **just-filled** slot pointer.

Typical call sites (hundreds of xrefs):

```c
// __thiscall  ECX = pool*
// stack: const char *src, int mode   // mode often -1 → use pool default
// ret 8
const char *StringPool_ApplyModeAndRingStore_Inferred(void *pool, const char *src, int mode);
```

Callers pass UI / dialog / chat literals (e.g. `"SYSTEM"`, login errors, item tooltip labels) with mode **`-1`** and treat the **return** as a temporary C-string for further UI packing. Because the ring has **10** slots, returned pointers are **ephemeral** (recycled after ~10 further successful stores).

Early outs (return **`src` unchanged**, no ring advance):

1. `src == NULL`
2. `*src == 0` (empty)
3. `src` **strcmp-equal** to sentinel **`"0"`** at `DAT_00a32460` (null-terminated single char `0x30`)

Otherwise:

1. Resolve effective mode: `mode == -1` → `*(int*)(pool + 0x2c)`, else `mode`.
2. `switch(effectiveMode)` **0..4** (modes ≥5 fall through switch with no transform body, still ring-advance — see gaps).
3. Advance ring index at `pool+0xc0`: `idx = *index; *index = (idx+1==10) ? 0 : idx+1`.
4. Return `*(char**)(pool + 4 + idx*4)` — the buffer written this call.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007a6de0_FUN_007a6de0.md` |
| Annotated | `docs/reconstruction/raw/aa_007a6de0_FUN_007a6de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007a6de0.cpp` (+ plate twin `Named_CalleeOf_Client_RecvDestroyObject_007a6de0.cpp`) |
| Function record | `docs/reconstruction/functions/aa_007a6de0_FUN_007a6de0.md` |
| Live | Ghidra `decompile_function` + `read_memory` OWN body + DAT tables |

**Three-rep:** present (scaffold 2026-07-23). This dual seals CF / ABI / key constants; does **not** claim bit-exact / runtime.

**OWN-only:** callee bodies `FUN_007a62c0` / `007a6310` / `007a6410` / `007a6490` / `007a6610` and `operator_new[]` / `delete[]` **not** dual-owned here.

---

## 3. Signature / ABI (image-sealed)

```c
// __thiscall
//   ECX          = StringPool* (manager with ring buffers)
//   [esp+4]      = const char *src   (byte*)
//   [esp+8]      = int mode          (-1 → pool+0x2c)
//   returns      = char*  (ring slot just written, or src on early-out)
//   cleanup      = ret 8
char *StringPool_ApplyModeAndRingStore_Inferred(void *pool, const char *src, int mode);
```

| Item | Evidence | Conf |
|---|---|---|
| ECX = this / pool | prolog `mov ebp, ecx` | **High** |
| Stack `src`, `mode` | prolog `mov edi, [esp+0x18]` after `sub esp,8` + 3 pushes; locals `param_2`/`param_3` | **High** |
| `ret 8` | epilog `add esp,8; ret 8` @ `0x007a70cb`–`0x007a70d0` (`83 c4 08 c2 08 00`) | **High** |
| Body span | `0x007a6de0`–`0x007a70d0` | **High** |
| Null / empty early-out | `test edi,edi` / `cmp byte [edi],0` → return `src` | **High** |
| `"0"` sentinel bypass | byte-pair strcmp vs `DAT_00a32460` = `{0x30,0x00}`; equal → `iVar6=0` → skip store, return `src` | **High** |
| Mode `-1` → `pool+0x2c` | `cmp param_3,-1` / load `[param_1+0x2c]` | **High** |
| Ring index `pool+0xc0`, wrap at 10 | epilog `mov ecx,[ebp+0xc0]; lea eax,[ecx+1]; cmp eax,10; … mov [ebp+0xc0],0` | **High** |
| Return slot `pool+4+idx*4` | `mov eax,[ebp+ecx*4+4]` | **High** |

### Pool layout (this unit only)

| Offset | Role | Conf |
|---|---|---|
| `+0x04` … `+0x04+9*4` | 10× `char*` ring buffer pointers | **High** |
| `+0x2c` | Default mode when call `mode == -1` | **High** |
| `+0x6c` … `+0x6c+9*4` | 10× capacity (`int`) used by mode **4** grow | **High** |
| `+0xc0` | Ring write index `0..9` | **High** |

---

## 4. Mode switch (OWN body)

| Mode | Behavior (OWN CF) | Conf |
|---|---|---|
| **0** | `FUN_007a62c0()` then **strcpy** `src` → current ring slot `*(pool+4+idx*4)` | **High CF** (callee body open) |
| **1 / 2 / 3** | `FUN_007a6490` + `FUN_007a6410` on `(pool, &mode)`; if **original** `mode == -1`: same strcpy path as 0; else `FUN_007a6310(effectiveMode, pool)` + `FUN_007a6610()` | **High CF shape**; transform English **Open** (callees not owned) |
| **4** | Ensure capacity ≥ `2 * strlen(src)`; zero buffer; **word-wise pig-latin** transform into ring slot (see §5) | **High** (constants + loops sealed) |
| other | No case body; still executes common ring advance + return current slot (contents may be stale) | **High CF** (gap for product) |

---

## 5. Mode 4 — pig-latin constants (sealed)

| Symbol | VA | Bytes / value | Role |
|---|---|---|---|
| Vowel table | `DAT_00a96fa0` | `int` array **`a e i o u y`** (6 entries; end bound `0x00a96fb4`) | Leading-vowel test |
| Consonant suffix | `DAT_00a96f9c` / `…f9e` | **`"ay\0"`** (`61 79 00`) | Append after moving onset |
| Vowel suffix | `DAT_00a800e4` | **`"yay\0"`** (`79 61 79 00`) | Append when word starts with vowel |
| Space | `0x20` | copied as word separator | Word split |

Algorithm (per non-space run, length `L = strlen(src)`):

1. If char is space → emit space.
2. Else if first char ∈ `{a,e,i,o,u,y}` → copy word to next space, append **`yay`**, out+=3.
3. Else → count leading consonants until vowel (or end); emit rest-of-word; emit leading consonants; append **`ay`**, out+=2.

Capacity: if `cap[idx] < 2*L`, `delete[]` old buffer, set cap, `new[]` new buffer at slot. Then **memset** slot to 0 for `cap` bytes before fill.

---

## 6. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Null / empty → return src | **Yes** | **High** |
| strcmp `"0"` → return src | **Yes** | **High** |
| mode -1 → `+0x2c` | **Yes** | **High** |
| switch 0 / 1–3 / 4 | **Yes** | **High** |
| Mode 0 strcpy after `FUN_007a62c0` | **Yes** | **High CF** |
| Mode 1–3 dual helper + branch on original mode==-1 | **Yes** | **High CF** |
| Mode 4 grow / zero / pig-latin | **Yes** | **High** |
| Ring bump wrap 10 + return prior slot | **Yes** | **High** |
| Callee product English | **N/A OWN** | open |

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Temp string ring + mode gate | **High** | full body + layout |
| ABI thiscall + `ret 8` | **High** | prolog/epilog |
| `"0"` sentinel bypass (not empty-only) | **High** | `DAT_00a32460` |
| Mode 4 = pig-latin (aeiouy / ay / yay) | **High structural** | product mode enum name open |
| Modes 1–3 = localization / case / charset | **Tentative** | helpers not owned |
| Default mode field `+0x2c` English | **Tentative** | offset sealed; product name open |
| Ephemeral 10-slot lifetime | **High** | wrap at 10 |
| Product class / PDB name | **Open** | leave `FUN_` / `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |
| Parent-seed plate name | **Low** | mislabels role |

---

## 8. Gaps

1. Product name of pool class and mode enum (0..4 English labels beyond mode-4 structure).
2. Semantics of `FUN_007a62c0` / `007a6490` / `007a6410` / `007a6310` / `007a6610` (ensure-capacity? locale tables?) — own duals required.
3. Whether mode ≥5 is intentional no-op vs decompiler/default fallthrough consumers care about.
4. Global singleton vs per-window pool identity at call sites (ECX source not sealed on OWN VA).
5. Why `"0"` is a hard bypass (placeholder / numeric zero string?).
6. Runtime golden + bit-exact open.

**Verdict:** **accept-with-gaps** — OWN CF, ABI, ring layout, `"0"` sentinel, and mode-4 pig-latin constants sealed **High** for AutoCore ports of UI string temps; leave mode 1–3 and product names residual.
