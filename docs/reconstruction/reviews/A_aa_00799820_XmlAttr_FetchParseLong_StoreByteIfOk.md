# Review A (reconstruction fidelity): `aa_00799820` XmlAttr_FetchParseLong_StoreByteIfOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799820` |
| **VA** | `0x00799820` |
| **Body span** | `00799820` – `0079984b` (**44 bytes**) |
| **Canonical name** | `XmlAttr_FetchParseLong_StoreByteIfOk` (**Inferred** structural) |
| **Ghidra name** | `FUN_00799820` |
| **Review date** | `2026-07-29` (W21-G dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00799820_XmlAttr_FetchParseLong_StoreByteIfOk.md` |
| **System** | XML / mission-def attribute parse |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Thin **XML attribute → byte** helper:

1. Call sealed `XmlAttr_FetchAndParseLong` (`FUN_00799460`) with a stack `long` temp.
2. If fetch success (`al != 0`): `*outByte = (uint8_t)tmp`.
3. If fail: leave `*outByte` unchanged.

Used heavily by mission objective XML deserializers for small numeric attrs (e.g. `slot` byte, flag-like fields stored as 1-byte).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00799820` |
| Bytes | `read_memory` 64 B — `call 00799460`; `test al,al`; byte store; `ret` |
| Bounds | `get_function_by_address` body `00799820`–`0079984b` |
| Callers | `get_function_callers` / xrefs ≥16 |
| Callee dual | `aa_00799460` XmlAttr_FetchAndParseLong |
| Parent sample | `FUN_00611a00` Collect_DeserializeXml: `L"slot"`, base `0xa`, `this+8` |
| Raw / clean | `aa_00799820_*`, `XmlAttr_FetchParseLong_StoreByteIfOk.cpp` |

**Not performed:** Launcher, full attr-name census, runtime.

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **`[esp+4]`** | node | pushed into callee arg0 |
| **`[esp+8]`** | attr name | pushed into callee arg1 |
| **`[esp+0xC]`** | `uint8_t *outByte` | used only on success path store |
| **`[esp+0x10]`** | base/radix | through to `wcstol` |
| **Return** | void | plain `ret` (`c3`) after `add esp,0x10` on callee |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **44 bytes** cdecl | **Confirmed** | bounds + `c3` + `cc` pad |
| Sole callee `00799460` | **Confirmed** | rel call target |
| Conditional low-byte store | **Confirmed** | `mov dl,[esp]; mov [ecx],dl` |
| Failed fetch no write | **Confirmed** | `jz` skips store |
| `base` is radix | **High** | sealed callee contract |
| Role = attr byte helper | **High** | parents + CF |
| All product attr names | **Open** | caller-owned |
| Runtime / differential | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| FetchAndParseLong(node, name, &tmp, base) | Yes |
| if ok → *out = low byte | Yes |
| else leave out | Yes |

### Recovered contract

```c
// void XmlAttr_FetchParseLong_StoreByteIfOk(node, attr, uint8_t* out, int base)
char ok = XmlAttr_FetchAndParseLong(node, attr, &tmp, base);
if (ok) *out = (uint8_t)tmp;
```

---

## 6. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00611a00` Collect_DeserializeXml | `slot` → `this+8`, base 10 |
| Caller | `CVOGObjectiveRequirement_UseItem_SerializeXml` | early attr helper |
| Caller | `FUN_00547050` MissionDef_ParseObjectiveXml | sequence/size probe (prior review) |
| Caller | others (xrefs) | mission/UI XML |
| Callee | `FUN_00799460` | fetch + `wcstol` |

---

## 7. Gaps / open

1. Exhaustive attr name / base radix table for all xrefs.
2. Whether truncation of multi-byte longs is ever intentional vs only 0–255 domain.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
