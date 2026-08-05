# Review A (reconstruction fidelity): `aa_00792980` NDUIWindow_ReloadInterface

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792980` |
| **VA** | `0x00792980` |
| **Body** | `0x00792980` – `0x00792a41` |
| **Canonical name** | `NDUIWindow_ReloadInterface` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00792980_NDUIWindow_ReloadInterface.md` |
| **System** | client UI / NDUI chrome (not a game-logic system unit) |
| **Dual status** | **Present** (2026-07-29 OWN-ONLY dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Reload / (re)skin an NDUI window from an interface path string**, then clear a cached sub-object and related pointer slots. When the path argument is **null**, additionally lock-traverse the window’s child hash (`this+0x4C0`) and hide every child via virtual `+0x28(0)`, then unlock the hash and invoke virtual `+0x34c`.

**Not** a network send, skill cast, inventory op, or mission mutation. Extremely hot UI leaf: **~241 xrefs** / dozens of distinct callers (options screens, target chrome, quickbar buttons, speed HUD, etc.) — almost always with a literal `i_*.xml` path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00792980_NDUIWindow_ReloadInterface.md` |
| Annotated | `docs/reconstruction/raw/aa_00792980_NDUIWindow_ReloadInterface.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDUIWindow_ReloadInterface.cpp` |
| Function record | `docs/reconstruction/functions/aa_00792980_NDUIWindow_ReloadInterface.md` |
| Live Ghidra | `decompile_function(0x00792980)` 2026-07-29 ≡ raw body |
| Live bytes | `read_memory(0x00792980, 64)` — prologue + field stores sealed |
| Callees | `get_function_callees` → `NDUIWindow_LoadInterfaceFile@0x007b0ef0`, `FUN_00411e10`, `FUN_007a4480` |
| Callers | `get_function_callers` / `get_xrefs_to` — 50+ listed; inventory coverage cites **241** xrefs |
| Sample callers | `FUN_00825bf0` → `"i_d_qb_2d_btn_quickbar.xml"`; options/XML ctors pass `i_o_*.xml` / `i_d_*.xml` |

**Not performed:** `disassemble_bytes`, Launcher, live process, bit-exact image diff. Callee **body** of `LoadInterfaceFile` is **out of unit** (own dual is separate VA `0x007b0ef0`).

---

## 3. Signature / ABI

```c
// MSVC __thiscall
// ECX = NDUIWindow* this
// stack0 = const char* pathOrNull  (often literal "i_*.xml"; null = no-file reload + hide-children path)
// returns void
void __thiscall NDUIWindow_ReloadInterface(NDUIWindow* this, const char* pathOrNull);
```

| Claim | Confidence | Evidence |
|---|---|---|
| `this` in `ECX` | **High** | `mov ebp, ecx` at entry after pushes (`read_memory`) |
| Stack arg = path pointer | **High** | `mov esi, [esp+0x10]` after 3 pushes; `push esi` before `call LoadInterfaceFile` |
| First callee = `NDUIWindow_LoadInterfaceFile` @ `0x007b0ef0` | **High** | Relative call target from bytes; callees list; name already assigned in Ghidra |
| Void return | **High** | Terminal return; no value materialization in decompile |
| `thiscall` field math uses dword indices | **High** | `param_1[0x12d..0x130]` ≡ byte offs `+0x4B4..+0x4C0` |

---

## 4. Control flow (sealed)

```
// thiscall; path in ESI after prologue
NDUIWindow_LoadInterfaceFile(path)          // always first — even if path == null

this[+0x4B8] = 0                            // dword index [0x12e]
this[+0x4BC] = 0                            // dword index [0x12f]

cached = this[+0x4B4]                       // dword index [0x12d]
if (cached != null) {
  (*cached->vtbl[0])(cached, 1)             // virtual release/dtor-with-delete flag 1
}
this[+0x4B4] = 0

if (path != null) {
  return                                    // normal XML (re)load path ends here
}

// ---- null-path only: hide all hash children ----
if (vtbl[+0x3d8](this) != 0                 // "has / may traverse children?" predicate
    && this[+0x4C0] != null) {              // hash root [0x130]
  FUN_00411e10()                            // lock hash for traversal (side effect on hash)
  node = null
  while (true) {
    hash = this[+0x4C0]
    if (hash[+0x1d] == 0) {                 // not locked → debug stop
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal")
      FUN_007a4480(0, "VOG_DEBUG_STOP")
    }
    node = (node == null) ? hash[+0x14] : node[+0x14]   // first / next chain
    child = (node == null) ? null : *(int**)(node + 8)
    if (child == null) break
    child->vtbl[+0x28](child, 0)            // hide / set-visible(false) style call
  }
  hash[+0x1d] = 0                           // unlock traversal flag
  vtbl[+0x34c](this)                        // post-hide refresh / layout hook
}
return
```

### Byte-level field seals (`read_memory` prologue)

| Store / load | Encoding | Byte offset | Dword index |
|---|---|---:|---:|
| load cached | `mov ecx,[ebp+0x4b4]` | `+0x4B4` | `0x12d` |
| zero slot A | `mov [ebp+0x4b8], ebx` | `+0x4B8` | `0x12e` |
| zero slot B | `mov [ebp+0x4bc], ebx` | `+0x4BC` | `0x12f` |
| clear cached | `mov [ebp+0x4b4], ebx` | `+0x4B4` | `0x12d` |
| null path test | `cmp esi, ebx` / `jnz` skip | path in ESI | — |

Live decompile ≡ raw capture (2026-07-23 scaffold + 2026-07-29 re-decompile): same order of Load → clear → optional dtor → null-path hash walk.

---

## 5. Callees (this unit only)

| VA | Name | Role in this unit | Confidence |
|---|---|---|---|
| `0x007b0ef0` | `NDUIWindow_LoadInterfaceFile` | Always called first with path (may be null) | **High** (identity); body **out of unit** |
| `0x00411e10` | `FUN_00411e10` | Hash traversal lock prelude | **Probable** (name from string context) |
| `0x007a4480` | `FUN_007a4480` | Debug/log on unlocked hash | **High** (literal strings) |

Virtuals (slots on `this` / children — product names open):

| Vtbl offset | Role (inferred) | Confidence |
|---:|---|---|
| `this+0x3d8` | Bool gate before child walk | **Probable** |
| `this+0x34c` | Post-walk refresh | **Probable** |
| `child+0x28` | Hide / set-visible(0) | **Probable** |
| `cached vtbl[0](1)` | Release owned sub-object | **High** (standard MSVC delete-dtor pattern) |

Hash node layout used **only as read pattern** (not full type seal):

| Off | Use |
|---:|---|
| `hash+0x1d` | byte lock flag (must be non-zero while walking; cleared after) |
| `hash+0x14` / `node+0x14` | next-node chain head / successor |
| `node+0x8` | child object* |

---

## 6. Callers (pattern, not exhaustive)

Coverage inventory: **241** xrefs. Sample sealed usages from clean/raw of other units and live decompiles:

| Caller | Path arg | Role |
|---|---|---|
| `FUN_00825bf0` / `UI_QuickBar_CreateSlotButton` | `"i_d_qb_2d_btn_quickbar.xml"` | QB slot button skin |
| `FUN_0081ab20` | `"i_o_video.xml"` | options video |
| `FUN_0081c460` | `"i_o_ui.xml"` | options UI |
| `FUN_0081d8d0` | `"i_o_physx.xml"` | options physx |
| `FUN_0081f2f0` | `"i_o_controls.xml"` | options controls |
| `FUN_00820830` | `"i_o_audio.xml"` | options audio |
| `FUN_00824410` | `"i_d_s_2d_btn_skill.xml"` | skill button skin |
| Combat target chrome | `"i_d_target.xml"` | target UI |
| Drive speed particles | `"i_d_speed.xml"` | speed HUD |
| `FUN_0082cfb0` / `FUN_0082a3a0` / `FUN_00841f60` | **forwarded** `param_2` | wrapper reload + post layout |

Null-path callers exist in the call graph (path == 0 branch is live code); product English for “clear skin / hide all” is **Probable**, not Confirmed by runtime.

---

## 7. Confidence table

| Claim | Level | Notes |
|---|---|---|
| Role: load/reload UI XML + clear cached subobject | **High** | Name + call pattern + body |
| Always calls `LoadInterfaceFile` first | **High** | Bytes + decompile |
| Fields `+0x4B4/+0x4B8/+0x4BC` clear / dtor | **High** | `read_memory` stores |
| Null path → hash walk + hide children | **High** CF; **Probable** “hide” product word | `vtbl+0x28(0)` pattern |
| `+0x4C0` is hash root | **High** | `HashError:TraverseToNext` strings |
| Exact product names of vtbl slots | **Tentative** | Need vtable map |
| Full semantics of LoadInterfaceFile | **Out of unit** | Separate dual |
| Bit-for-bit / runtime | **Open** | Not run |

---

## 8. Gaps

1. Product RTTI / full `NDUIWindow` layout beyond the four dword slots touched here.  
2. Precise meaning of `vtbl+0x3d8` / `+0x34c` / child `+0x28`.  
3. Whether `LoadInterfaceFile(null)` is a no-op or clears prior XML (callee dual).  
4. Who passes `path == null` in retail flows (caller audit residual).  
5. Runtime / differential verification open.

---

## 9. AutoCore impact

- **Client UI only** — no server packet, no persistence.  
- When porting client chrome: every window skin construction that today calls this VA must still (1) load XML via `LoadInterfaceFile`, (2) clear `+0x4B4..+0x4BC` ownership, (3) honor null-path hide-all if any host uses it.  
- Do **not** invent network or gameplay side effects on this leaf.

**Verdict:** CF and ownership-clear sequence **sealed High**. Product names of virtuals and full load-file body remain residual → **accept-with-gaps**.
