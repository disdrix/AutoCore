# Review A (reconstruction fidelity): `aa_0076cf00` Profiler_ScopeEnter

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cf00` |
| **VA** | `0x0076cf00` |
| **Body** | `0x0076cf00` – `0x0076cf05` |
| **Canonical name** | `FUN_0076cf00` (Probable: `Profiler_ScopeEnter`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (profiler scope enter stub) |
| **Counterpart** | `reviews/B_aa_0076cf00_Profiler_ScopeEnter.md` |
| **System** | client instrumentation / profiler |
| **Path context** | Global `DAT_00d1f040`; pair leave `FUN_0076cef0`; timer slot +4 (zone ctor) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Named profiler scope enter** used at the top of many client systems (AI heartbeats, sector step, vehicle move, FX load, CLoadNode init, …).

Authoritative body (this retail image):

1. Treat **ECX** as profiler context object.
2. Return **`*(ECX + 4)`** (timer block pointer).
3. Clean **4** bytes of stack (the zone **name** pointer) via **`ret 4`**.
4. **Do not** read the name; **do not** sample QPC; **do not** push a zone stack.

Call sites still push human-readable names (`"CVOGSectorMap::StepTo"`, `"LoadMasterFromXML"`, `"CVOGVehicle::MoveToTarget3DPoint"`, …) and load `ECX = *DAT_00d1f040` for ABI compatibility with a fuller profiler build. Leave is `FUN_0076cef0` (`ret` only).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076cf00_FUN_0076cf00.md` (+ 2026-07-29 refresh) |
| Annotated | `docs/reconstruction/raw/aa_0076cf00_FUN_0076cf00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0076cf00.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Profiler_ScopeEnter.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076cf00_FUN_0076cf00.md` |
| Live decompile | Ghidra `decompile_function` @ `0x0076cf00` ≡ raw |
| Body bytes | `read_memory` 6 B — `8b 41 04 c2 04 00` |
| Leave sibling | `read_memory` @ `0x0076cef0` — `c3` |
| Call sites | `read_memory` @ `0x004a6390`, `0x004d6c80`, `0x004fc650` — `mov reg,[DAT_00d1f040]` + `push` name + `mov ecx,reg` + `call` |
| String | `read_memory` `0x009ca1c0` = `"LoadMasterFromXML"`; `0x009cc79c` = `"CVOGSectorMap::StepTo"` |
| Related duals | `Profiler_TimerBlock_Ctor` / `Profiler_Zone_Ctor` (timer at +4) |

**Not performed:** `disassemble_bytes`, Launcher, live QPC. **OWN VA only.**

---

## 3. Signature

```c
void *Profiler_ScopeEnter(void *profilerCtx /* ECX */, const char *name /* stack, ignored */);
// ret 4; EAX = *(profilerCtx + 4)
```

| Slot | Role | Evidence |
|---|---|---|
| `ECX` | Profiler context* | `[ecx+4]` load; callers set from `DAT_00d1f040` |
| `stack0` | Name C-string | call-site push; `ret 4`; unread |
| `EAX` | Timer* | `mov eax,[ecx+4]` |

Decompiler `undefined4 __fastcall FUN_0076cf00(int param_1)` is incomplete without stack/`ret 4` documentation.

---

## 4. Layout touch

| Offset | Field | This function |
|---|---|---|
| `ctx+0x04` | Timer block* | **read** → return |

No stores. Zone ctor dual owns writing timer into `+4`.

---

## 5. Control flow (sealed)

```
Profiler_ScopeEnter(ctx /* ECX */, name /* ignored */):
  return *(ctx + 4)
```

Linear; zero branches. Live decompile ≡ original raw. Three-rep: raw ≡ live decomp ≡ body bytes.

---

## 6. Callers (representative)

| Site | Function | Name literal |
|---|---|---|
| `0x004a63cb` | `FUN_004a6390` FxMaster load | `"LoadMasterFromXML"` |
| `0x004d6cae` | `FUN_004d6c80` StepTo | `"CVOGSectorMap::StepTo"` |
| `0x004fc683` | `FUN_004fc650` drive | `"CVOGVehicle::MoveToTarget3DPoint"` |
| many | AI / CLoadNode / PhysX / … | matching plate strings |

Inventory ~120 xrefs — high fan-in instrumentation leaf.

---

## 7. Confidence

| Claim | Level |
|---|---|
| Bytes / ABI / return +4 | **Confirmed** |
| Name dead in body | **Confirmed** |
| Profiler enter role (stub) | **High** |
| `DAT_00d1f040` current ctx | **High** |
| Product spelling | **Probable** |

---

## 8. Gaps

1. Product C++ name.
2. Full type of `*DAT_00d1f040` beyond timer at +4.
3. Whether any caller consumes EAX timer.
4. Runtime / bit-diff.

**Verdict:** **accept** — sealed stub contract; no residual blocking instrumentation classification.
