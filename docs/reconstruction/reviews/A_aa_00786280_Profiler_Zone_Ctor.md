# Review A (reconstruction fidelity): `aa_00786280` Profiler_Zone_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786280` |
| **VA** | `0x00786280` |
| **Canonical name** | `FUN_00786280` (Probable: `Profiler_Zone_Ctor`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (zone node in-place ctor) |
| **Counterpart** | `reviews/B_aa_00786280_Profiler_Zone_Ctor.md` |
| **System** | client instrumentation / profiler internals |
| **Path context** | Callers: FindOrCreateChildZone `0x00786532`; EnsureThreadSlot `0x007867a6` (`"Hermann"`, parent=0) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-place construct a profiler zone node** of size **0x5c**:

1. `self->name = name` (`+0`).
2. `self->timer = 0` then allocate/construct later (`+4`).
3. `self->parent = ECX` (`+8`) — **NULL** for thread-root `"Hermann"`.
4. Zero child-pointer vector (`+0x10/+0x14/+0x18`).
5. Build empty name→child **map**: `FUN_0044e100` header → `+0x20`, ring left/parent/right, nil `@head+0x2d=1`, size `+0x24=0`.
6. Zero stats `+0x28..+0x54` (includes nest `+0x3c`, hierarchical `+0x28` used by siblings).
7. Flag byte `+0x58 = 1`.
8. `operator_new(0x30)` + `FUN_00780730` (ESI) → timer at `+4`; OOM leaves null.
9. Return **self** in EAX; **`ret 8`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00786280_FUN_00786280.md` (+ 2026-07-29 refresh) |
| Annotated | `docs/reconstruction/raw/aa_00786280_FUN_00786280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00786280.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Profiler_Zone_Ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00786280_FUN_00786280.md` |
| Live decompile | `decompile_function` @ `0x00786280` ≡ raw |
| Body bytes | `read_memory` — `ret 8` (`c2 08 00`); ECX→`+8`; timer path `mov esi,eax; call 00780730` |
| Header helper | `decompile_function` `FUN_0044e100` — `new(0x30)` tree node |
| Timer ctor | owned sibling `0x00780730` dual |
| Callers | `decompile_function` `0x00786470`, `0x007866e0` |
| Hermann | `read_memory` `0x00a9adc4` = `"Hermann\0"` |
| Xrefs | `get_xrefs_to` — **2** sites |

**Not performed:** `disassemble_bytes`, Launcher, full STL map dual. **OWN VA.**

---

## 3. Signature (assembly-backed)

```c
// Hybrid register+stack: parent in ECX; self + name on stack; ret 8; EAX=self
Zone *Profiler_Zone_Ctor(Zone *parent /*ECX*/, Zone *self /*stack0*/, const char *name /*stack1*/);
```

| Slot | Role | Evidence |
|---|---|---|
| `ECX` / decomp `param_1` | **Parent** zone* (nullable) | `mov [edi+8], ecx`; EnsureThreadSlot `xor ecx,ecx` |
| stack0 / `param_2` | **Self** zone* | `mov edi, [esp+…]`; returned in EAX |
| stack1 / `param_3` | **Name** C-string | stored at `+0`; callers push name / `"Hermann"` |
| Return | self | `mov eax, edi` |
| Cleanup | `ret 8` | body end `c2 08 00` |

Ghidra `__thiscall` is easy to misread: **ECX is parent, not self**.

---

## 4. Layout (zone 0x5c)

| Offset | Field | Evidence |
|---|---|---|
| `+0x00` | name `const char*` | `*self = name` |
| `+0x04` | timer* | new+`00780730` |
| `+0x08` | parent* | ECX |
| `+0x0c` | unwritten | no store in body |
| `+0x10..+0x18` | child ptr vector | zero triple; push via `FUN_004406e0` elsewhere |
| `+0x1c` | map base | insert `FUN_004309c0(zone+0x1c)` (caller dual) |
| `+0x20` | map head | `FUN_0044e100` |
| `+0x24` | map size | 0 |
| `+0x28` | hierarchical total (consumer) | zeroed; leave adds |
| `+0x3c` | nest count (consumer) | zeroed; start ++ |
| `+0x58` | flag | **1** |

---

## 5. Control flow (sealed)

```
Profiler_Zone_Ctor(parent, self, name):
  self.name = name
  self.timer = 0
  self.parent = parent
  zero child vector
  head = TreeHeader_New()          // FUN_0044e100
  install empty map (head ring, size 0)
  zero +0x28..+0x54; flag=1
  t = new TimerBlock(0x30)
  if t: self.timer = TimerBlock_Ctor(t) else self.timer = 0
  return self
```

Live decompile ≡ raw. Branch: timer OOM only.

---

## 6. Callers

| Site | Function | Role |
|---|---|---|
| `0x00786532` | `Profiler_FindOrCreateChildZone` | Child zone under parent |
| `0x007867a6` | `Profiler_EnsureThreadSlot` | Root zone name `"Hermann"`, parent NULL |

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI ECX parent + 2 stack + ret 8 | **High** | Body + both callers |
| Alloc 0x5c | **High** | Both callers |
| Timer path | **High** | Own dual `00780730` |
| Empty map header install | **High** | Body bytes |
| Child vector @ +0x10 | **High** | Zero + sibling push |
| `+0x0c` meaning | **Low** | Unwritten |
| Flag `+0x58` English | **Med** | Value sealed, name open |
| Product class name | **Probable** | |

---

## 8. Surviving contract (port)

```
// Client profiler zone node (0x5c):
//   Zone* Profiler_Zone_Ctor(Zone* parent /*ECX*/, Zone* self, const char* name);
// Root: parent=null, name="Hermann"
// Child: parent=current zone, name=zone label
```

---

## 9. Open residual

1. Full dual of `FUN_0044e100` / map node payload layout.  
2. Field English for `+0x0c` and each zeroed stat dword beyond nest/hierarchical.  
3. Whether name pointer is owned or borrowed (stores raw `const char*` — both callers pass string literals / stable params).  
4. Runtime / bit-diff.

**Verdict:** **accept-with-gaps** — construct ABI + core layout dual-ready; residual map/stat English.
