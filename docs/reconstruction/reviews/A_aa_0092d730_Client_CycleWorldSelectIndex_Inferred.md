# Review A (reconstruction fidelity): `aa_0092d730` Client_CycleWorldSelectIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092d730` |
| **VA** | `0x0092d730` |
| **Canonical name** | `Client_CycleWorldSelectIndex_Inferred` |
| **Prior names** | `FUN_0092d730`, `Named_CalleeOf_Client_Input_PollBoundActions_0092d730` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0092d730_Client_CycleWorldSelectIndex_Inferred.md` |
| **System** | `interaction-activation` / client input select |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Advance the client’s **world-object selection cursor** one step, skipping the local character, and bind a resolved object side-pointer:

```text
// EAX = Client*
++*(byte*)(client+0x4f8)          // selection index
world = *(client+0xe04)
// vector of object* at world+0xe75c .. +0xe760 (count = (end-begin)/4)

while index < count:
  if count <= index_byte: index = 0     // wrap
  obj = begin[index]
  if obj != *(client+0xe98): break      // skip local character
  ++index; ++safety_counter
  if safety exhausted: return           // full loop of only-local / empty

if obj != 0:
  client+0xe08 = *( *(obj+4) + 4 ) + 4 + obj   // embedded subobject / interface ptr
else:
  client+0xe08 = 0
```

Callers: `Client_Input_PollBoundActions`, focus/select helpers, client frame `FUN_009440e0`. Often followed by target apply (`FUN_0093e120`) or binding checks on `client+0xe08`.

---

## 2. Calling convention — **SEALED**

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | `Client*` | Prologue `add byte [eax+0x4f8],1`; sites `mov eax, client` / `0xd1a840` |
| Return | `void` | |
| Stack | none | |

Live prologue (`read_memory`):

```text
0092d730  add  byte ptr [eax+0x4f8], 1
0092d737  mov  dl, [eax+0x4f8]
0092d73d  push ebx
0092d73e  push esi
0092d73f  mov  esi, [eax+0xe04]
```

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / record | `aa_0092d730_*` |
| Live decompile | Ghidra `batch_decompile` `0x0092d730` |
| Live bytes | `read_memory` length 48 |
| Callers | `Client_Input_PollBoundActions` `0x00925db2`, `FUN_0091c220`, `FUN_009423b0`, `FUN_009440e0` |
| Call-site | After call, some paths write camera/UI; `FUN_009423b0` then `FUN_0093e120` select |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Pre-increment `+0x4f8` | **Yes** |
| Vector length `(end-begin)>>2` with null-begin → 0 | **Yes** |
| Wrap index to 0 when past end | **Yes** |
| Skip entries equal to `client+0xe98` | **Yes** |
| Safety counter prevents infinite skip | **Yes** |
| Bind `+0xe08` via object RTTI/embedded layout `*(obj+4)+4+4+obj` | **Yes** |
| Null obj → `+0xe08=0` | **Yes** |

### Offsets

| Offset | Role |
|--------|------|
| client `+0x4f8` | u8 selection index |
| client `+0xe04` | world / map host |
| client `+0xe08` | resolved select side-ptr |
| client `+0xe98` | local character (skip) |
| world `+0xe75c` / `+0xe760` | object* vector begin/end |

---

## 5. Naming / gaps

| Claim | Confidence |
|---|---|
| Role = cycle select index skip local | **High** |
| EAX client | **High** |
| Product name of `+0xe08` interface | **Tentative** |
| Exact vector population owner | **Open** |
| Runtime | **Open** |

---

## 6. Verdict

**accept-with-gaps** — index wrap, skip-local, and `+0xe08` bind sealed from live bytes.
