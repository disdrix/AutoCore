# Annotated low-level: Client_InitPalantirViewBundle_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004cda90` |
| VA | `0x004cda90`–`0x004cdc34` exclusive (**420 B** / `0x1A4`) |
| Ghidra | `FUN_004cda90` |
| Semantic | `Client_InitPalantirViewBundle_Inferred` |
| System | client / Palantir graphics + env bootstrap |
| Date | 2026-07-29 (W30-F) |

## Machine-level notes

- **ABI:** `__thiscall`/`__fastcall`; ECX = large parent (client core / world host); bare `C3`; returns `1`.
- **SEH:** `LAB_009a1ef7`; three construction scopes (SEH levels 0/1/2) around the three `operator_new`+ctor pairs.
- **ESI** holds parent after entry (`8B F1`).
- **Do not invent product English** beyond path evidence from callees (`gfxView.cpp`, Palantir desktop string on sole caller).

## Control flow (annotated)

```c
// ECX = parent*
// returns 1 on success path (always, if no throw)

// 1) GfxView 0x150
view = operator_new(0x150);
view = view ? FUN_0075ceb0(view) : 0;   // gfxView.cpp / PalViewBackground.fx
parent->e890 = view;

// 2) near/far style floats on view (thiscall ECX=view)
FUN_0075b3b0(view, 0.5f);               // view+0xF0
far = (parent->byte_7d == 0) ? 500.f : 1000.f;  // DAT_00aaaa90 / DAT_00a0f520
FUN_0075b390(view, far);                // view+0xF4

// 3) optional Palantir desktop window object at parent+0xE89C
if (desktop = parent->e89c) {
  desktop->2e4 = view;
  (**(desktop->2c->vtbl + 0xC))(view);  // vcall slot 3
  desktop->2c->c4 = DAT_00afdef0;       // 0xFF000000
}

// 4) env/list host 0x198
env = operator_new(0x198);
env = env ? FUN_00492dd0(env, 0, parent) : 0;
parent->e894 = env;

// 5) Class_009c7a1c 0xC8 (W29-G)
helper = operator_new(0xC8);
helper = helper ? Class_009c7a1c_Ctor(helper, parent) : 0;  // FUN_00496f70
parent->e898 = helper;

// 6) cross-wire
view->4 = env;
env->c0 = view;

// 7) environment phases on env (water/distort/fx; VOGEnvironmentSector.cpp)
FUN_0048fc90(env, 1);

// 8) global publish of *(env+4)
if (DAT_00d1a54c) FUN_0074e200(0);      // disable previous
slot = *(int*)(env + 4);
if (slot) FUN_0074e200(1);              // enable new
DAT_00d1a54c = slot;

return 1;
```

## Call graph

| Direction | Target | Note |
|---|---|---|
| Caller | `FUN_00948530` | sole; after desktop ptr → `parent+0xE89C`; before `"Could not get Palantir desktop window."` fail path |
| Callee | `FUN_0075ceb0` | GfxView complete ctor (`sizeof 0x150`) |
| Callee | `FUN_00492dd0` | env host ctor (`sizeof 0x198`, arg0=0, arg1=parent) |
| Callee | `FUN_00496f70` | `Class_009c7a1c_Ctor` (W29-G; `sizeof 0xC8`) |
| Callee | `FUN_0048fc90` | env sector phase init on `e894` |
| Related | `FUN_0075b3b0` / `FUN_0075b390` | view float stamps `+0xF0` / `+0xF4` |

## Open gaps

- Product demangle for parent type and `FUN_00492dd0` class.
- Exact semantic of `parent+0x7d` (mode bit selecting 500 vs 1000).
- `FUN_0074e200` / `DAT_00d1a54c` product role.
- Runtime / bit-exact / differential.
