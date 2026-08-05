# Review A (reconstruction fidelity): `aa_004149d0` CVOGReaction_FailMissionNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_004149d0` |
| **VA** | `0x004149d0` |
| **Canonical name** | `CVOGReaction_FailMissionNotify` (historical) |
| **Product alias (sealed)** | **`Vector_PushDword`** |
| **Review date** | `2026-07-29` (dual residual strengthen — pure push seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + image) |
| **Counterpart** | `reviews/B_aa_004149d0_CVOGReaction_FailMissionNotify.md` |
| **System** | container util (cross-cutting; not mission-only) |
| **Dual status** | **Present and strengthened** (supersedes 2026-07-23 accept-with-gaps) |
| **Verdict** | **accept** on pure `Vector_PushDword` CF + multi-caller generic role |

---

## 1. Purpose

**Pure growable dword-vector push** (`std::vector<uint32_t>`-shaped triad). Historical name comes from an early FailMission call-graph edge; the body is a **generic multi-caller container helper** with **no** mission fail, UI, network, dirty-bit, hash, or toast logic.

```
Vector_PushDword(this, dword*)
  begin = *(this+4); end = *(this+8); cap = *(this+0xc)
  if begin != 0 && (end-begin)/4 < (cap-begin)/4:
    *end = *value; end += 4; return
  else:
    FUN_0040dbf0(/*thiscall this*/, &argSlot, end, valuePtr)  // grow/insert path
```

**Calling convention (image-sealed):**

| Slot | Role | Evidence |
|------|------|----------|
| `ECX` | vector object (`this`) | `__thiscall`; triad at `+4/+8/+0xc` |
| stack `arg0` | `uint32_t*` value pointer | `MOV EDX,[ESP+8]` after `PUSH ESI` |
| return | `void` | fall-through |
| cleanup | `RET 4` | callee pops 1 dword arg |

**Side effects:** Mutates only the vector triad (`begin`/`end`/`cap` pointers) and buffer contents. No globals, no packets, no mission state.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004149d0_CVOGReaction_FailMissionNotify.md` |
| Annotated | `docs/reconstruction/raw/aa_004149d0_CVOGReaction_FailMissionNotify.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_FailMissionNotify.cpp` |
| Function record | `docs/reconstruction/functions/aa_004149d0_CVOGReaction_FailMissionNotify.md` |
| Prior dual | A/B 2026-07-23 (accept-with-gaps; rename / drain open) |
| Live re-decompile | Ghidra `decompile_function` `0x004149d0` (2026-07-29) — **≡ raw body** |
| Image | `read_memory 0x004149d0` length `0x50` |
| Grow chain | decompile `FUN_0040dbf0` `0x0040dbf0` → `FUN_004073a0` `0x004073a0` |
| Callers | `get_function_callers` → **40** functions |
| Xrefs | `get_xrefs_to` → **51** `UNCONDITIONAL_CALL` sites |
| Related duals | FailMission `aa_0052da30`, Journal `aa_008ae130` (site-level push confirm) |

**Not performed:** `disassemble_bytes` bulk, Launcher, runtime push golden, Ghidra rename commit.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live decompile | **High** | Byte-identical CF spine |
| `__thiscall(vec*, dword*)` + `RET 4` | **High** | Image |
| Triad `this+4` begin / `+8` end / `+0xc` cap | **High** | Image + all known sites |
| Element stride **4** (`SAR …,2`) | **High** | Fast path size/cap math |
| Fast path: `*end = *arg; end += 4` when capacity remains | **High** | Image `89 10` / `83 C0 04` / `89 41 08` |
| Slow path: `FUN_0040dbf0` → `FUN_004073a0` reallocate/insert | **High** | Callee decompiles |
| **No** fail / UI / packet / dirty / hash in body | **High** | Zero other callees |
| Name is historical; product role = **`Vector_PushDword`** | **High** | 40 callers; freelist + medal + journal + fail |
| Element type always mission id | **Falsified** | Freelist ptr, medal id, stack temps, end-quest ids |
| `this` layout always `char+0x560` | **Falsified** | Journal stack `ESP+0x24/0x34`; freelist wrappers |
| Growth factor / exact `_Insert_n` product name | **Probable** | `FUN_004073a0` 1.5× + `operator_new(n*4)` |
| Bit-exact / runtime | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ image

| Stage | Match |
|---|---|
| Load begin `@this+4` | **Yes** (`MOV ESI,[ECX+4]`) |
| Size = 0 if begin null else `(end-begin)>>2` | **Yes** |
| Grow if begin null **or** size ≥ capacity | **Yes** |
| Fast store `*end=*arg`, end+=4 | **Yes** |
| Else `CALL FUN_0040dbf0` with thiscall ECX | **Yes** (`E8` → `0x0040dbf0`) |
| `POP ESI` / `RET 4` both exits | **Yes** |
| No invented mission logic | **Yes** |

### 4.1 Image spine (length `0x50`)

```
004149d0  PUSH ESI
004149d1  MOV  ESI, [ECX+4]              ; begin
004149d4  TEST ESI, ESI
004149d6  JNZ  has_begin
004149d8  XOR  EDX, EDX                  ; size = 0
004149da  JMP  check_cap
004149dc has_begin:
          MOV  EDX, [ECX+8]
          SUB  EDX, ESI
          SAR  EDX, 2                    ; size = (end-begin)/4
004149e4 check_cap:
          TEST ESI, ESI
          JZ   grow                      ; null begin → grow
          MOV  EAX, [ECX+0xC]
          SUB  EAX, ESI
          SAR  EAX, 2                    ; capacity
          CMP  EDX, EAX
          JAE  grow
          MOV  EAX, [ECX+8]              ; end
          MOV  EDX, [ESP+8]              ; arg0 = dword*
          MOV  EDX, [EDX]
          MOV  [EAX], EDX                ; *end = *arg
          ADD  EAX, 4
          MOV  [ECX+8], EAX              ; end++
          POP  ESI
          RET  4
00414a09 grow:
          MOV  EDX, [ESP+8]
          MOV  EAX, [ECX+8]
          PUSH EDX
          PUSH EAX
          LEA  EAX, [ESP+0x10]           ; &stack_arg0
          PUSH EAX
          CALL FUN_0040dbf0              ; thiscall ECX=vec
          POP  ESI
          RET  4
```

### 4.2 Grow chain (not mission-semantic)

| VA | Role |
|----|------|
| `0x0040dbf0` `FUN_0040dbf0` | Compute insert index from triad; call insert-n with count=1 |
| `0x004073a0` `FUN_004073a0` | Capacity grow (1.5× / min fit), `operator_new(n*4)`, relocate dwords, update triad |

---

## 5. Multi-caller inventory (generic proof)

**40** caller functions / **51** call sites (`get_function_callers` / `get_xrefs_to`).

| Class | Examples | `this` / element |
|-------|----------|------------------|
| FailMission end-quest queue | `CVOGReaction_FailMission` `0x0052da30` | `char+0x560`; mission id (`LEA ECX,[ESI+0x560]`) |
| Journal temp Active/New | `Client_UpdateMissionJournal` `0x008ae130` | stack `ESP+0x24` / `ESP+0x34`; mission id |
| Medal / award notify list | `FUN_00530550` | character-side list; medal/id + dirty `\|0x20` **in caller** |
| Aligned freelist / pool bootstrap | `FUN_00414cd0`, `FUN_00419bd0`, `FUN_0044c150/1b0/210`, … | freelist head vector; **pointer** to allocated slab |
| Vehicle / object lists | `FUN_004ff630`, others | domain-specific dword* |
| Misc UI / net / map helpers | remaining xref set | various |

**Sealed implication:** treating this unit as “fail mission notify” is **wrong**; call-site semantics own the element meaning and any follow-on dirty/UI/drain.

---

## 6. Gaps (after residual strengthen)

1. ~~Is body fail UX / teardown?~~ **Sealed: pure Vector_PushDword.**
2. ~~Mission-id-only element?~~ **Sealed: falsified (multi-caller).**
3. ~~Always `char+0x560`?~~ **Sealed: falsified (stack + freelist + others).**
4. Optional Ghidra/registry rename to `Vector_PushDword` (historical name retained in artifacts for xref continuity).
5. Full dual of grow callees `FUN_0040dbf0` / `FUN_004073a0` as own units (roles sealed; product English open).
6. Exhaustive per-site element-type table for all 51 sites (sample classes sealed; full table open).
7. Bit-exact / runtime golden.

---

## 7. Verdict

**Pure `Vector_PushDword` is sealed** — capacity-checked in-place dword append, overflow via `FUN_0040dbf0`→`FUN_004073a0`, `__thiscall` + `RET 4`, multi-caller generic. Historical `CVOGReaction_FailMissionNotify` name is call-graph residue only.

**Verdict: accept** (push CF + generic role) / residual gaps limited to rename hygiene + full grow dual + exhaustive site taxonomy.
