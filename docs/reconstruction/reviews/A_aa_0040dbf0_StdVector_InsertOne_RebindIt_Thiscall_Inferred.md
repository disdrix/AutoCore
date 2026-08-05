# Review A (reconstruction fidelity): `aa_0040dbf0` StdVector_InsertOne_RebindIt_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dbf0` |
| **VA** | `0x0040dbf0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Thiscall_Inferred` |
| **Ghidra name** | `FUN_0040dbf0` |
| **Prior scaffold** | `FUN_0040dbf0` / `Named_CalleeOf_CVOGReaction_FailMissionNotify_0040dbf0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-G) |
| **Counterpart** | `reviews/B_aa_0040dbf0_StdVector_InsertOne_RebindIt_Thiscall_Inferred.md` |
| **System** | util / container (std::vector&lt;dword&gt;) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Insert exactly one dword** into an MSVC-style vector, then **rebind an out-iterator** so it remains valid after a possible reallocation of `begin`.

```text
// ECX = vector*  (+4 begin, +8 end, +0xC capEnd)
// stack: outIt**, pos*, value*
index = empty(vec) ? 0 : (pos - begin) / 4
FUN_004073a0(vec, pos, count=1, value*)   // may realloc
*outIt = begin' + index*4
ret 0x0C
```

Primary known caller: **`CVOGReaction_FailMissionNotify`** (`0x004149d0`) capacity-full push_back slow path (fast path writes `*end++` when room remains).

**Twin** (same CF, different ABI/callee): `aa_00466da0` `StdVector_InsertOne_RebindIt_Inferred` → `FUN_00456960`.

**Not** multi-insert API, erase, capacity query, or domain/mission logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | `vector*` host |
| stack0 | `T**` out-iterator holder |
| stack1 | insert position (`T*` into buffer; push_back passes `end`) |
| stack2 | `const T*` value source |
| return | void (`*outIt` written); **`ret 0x0C`** |

```c
void __thiscall StdVector_InsertOne_RebindIt_Thiscall(
    void *vec, void **outIt, void *pos, const void *value);
```

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0040dbf0` (2026-07-29) ≡ raw |
| Bytes | `read_memory` 70 B — `6A 01`, `call FUN_004073a0`, `lea edx,[ecx+esi*4]`, **`C2 0C 00`** |
| Parent | `decompile_function` `CVOGReaction_FailMissionNotify` @ `0x004149d0` |
| Callee dual | `A_aa_004073a0_StdVector_InsertN_Dword_Inferred` |
| Twin dual | `A_aa_00466da0_StdVector_InsertOne_RebindIt_Inferred` |
| Raw / annotated / clean | `aa_0040dbf0_*`, `reconstructed-exact/FUN_0040dbf0.cpp` |
| Callers | `get_function_callers` → `CVOGReaction_FailMissionNotify` only (listed) |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin; empty → index 0 | **Yes** |
| Else index = (pos−begin)>>2 | **Yes** |
| Call insert-N with count **1** | **Yes** (`push 1`) |
| Rebind `*outIt = begin' + index*4` | **Yes** (`lea`/`mov`) |
| `ret 0x0C` | **Yes** (bytes; scaffold previously omitted) |
| Invented branches | **None** |

### Recovered CF

```c
// __thiscall; ret 0x0C
void InsertOne_RebindIt(void *vec, void **outIt, void *pos, const void *val)
{
  int begin = *(int *)((char *)vec + 4);
  int index;
  if (begin == 0 || ((*(int *)((char *)vec + 8) - begin) >> 2) == 0)
    index = 0;
  else
    index = ((int)pos - begin) >> 2;
  FUN_004073a0(vec, (int)pos, 1, (unsigned)val); // thiscall
  *outIt = (void *)(*(int *)((char *)vec + 4) + index * 4);
}
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element stride **4** | **Confirmed** | `>>2`, `*4`, `lea [ecx+esi*4]` |
| Hardcoded insert **count = 1** | **Confirmed** | `6A 01` |
| Index save before realloc, rebind after | **Confirmed** | ESI index; write after call |
| `ret 0x0C` / three stack formals | **Confirmed** | `C2 0C 00` |
| ECX = vector; layout +4/+8 | **Confirmed** | body + parent |
| Callee `FUN_004073a0` = insert-N | **High** | dual sealed |
| Push_back slow path role | **High** | parent CF |
| Decompiler elides `this` on call | **Confirmed** | artifact only |
| Product / STL symbol name | **Open** | `_Inferred` |
| Sole caller forever | **Probable** | one listed xref; other sites possible |

---

## 6. Gaps / open

1. Product mangled name (structural kept).
2. Whether additional indirect / unlisted call sites exist beyond FailMissionNotify.
3. Element semantic domain is caller-specific (generic dword bag here).
4. Runtime / bit-exact deferred.
5. Full grow policy owned by `aa_004073a0` dual (not re-litigated).

**Verdict:** **accept-with-gaps** — ABI + one-element rebind-insert CF sealed High; structural name.
