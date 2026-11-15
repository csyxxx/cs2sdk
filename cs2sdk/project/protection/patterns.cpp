#include <pch/pch.hpp>
#include <protection/game_addresses.hpp>

namespace patterns {

	const ::protection::addresses::address_t& add_entity = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 74 24 10 57 48 83 EC 20 41 B9 FF 7F 00 00 41 8B C0 41 23 C1 48 8B F2 41 83 F8 FF 48 8B F9 44 0F 45 C8 41 81 F9 00 40 00 00 73 0D FF 81 20"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 74 24 10 57 48 83 EC 20 41 B9 FF 7F 00 00 41 8B C0 41 23 C1 48 8B F2 41 83 F8 FF 48 8B F9 44 0F 45 C8 41 81 F9 00 40 00 00 73 0D FF 81 20");

	const ::protection::addresses::address_t& base_fire_guns_get_inaccuracy = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 10 55 56 57 48 81 EC ? ? ? ? 44 0F 29 84 24 80 00 00 00"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 10 55 56 57 48 81 EC ? ? ? ? 44 0F 29 84 24 80 00 00 00"); // >E8????????84C00F84C6FEFFFF

	const ::protection::addresses::address_t& button_state_alloc = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B54CA088D4101894708EB16488B0F>E8????????488BD0488BCF-80"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B54CA088D4101894708EB16488B0F>E8????????488BD0488BCF-80");

	const ::protection::addresses::address_t& cmd_interpreter = ADDRESS_IMPL(
		::protection::addresses::hash("rendersystemdx11.dll:>E8????????4183BDC000000000"),
		::protection::addresses::address_type::pattern,
		"rendersystemdx11.dll:>E8????????4183BDC000000000");

	const ::protection::addresses::address_t& create_move = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40 18"),
		::protection::addresses::address_type::pattern,
		"client.dll:85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40 18");

	const ::protection::addresses::address_t& csgo_input = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 8B 0D * ? ? ? ? 4C 8B C6 8B 10 E8 ~"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 8B 0D * ? ? ? ? 4C 8B C6 8B 10 E8 ~");

	const ::protection::addresses::address_t& draw_flash_effect = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:85D20F88????????48894C24??5556"),
		::protection::addresses::address_type::pattern,
		"client.dll:85D20F88????????48894C24??5556");

	const ::protection::addresses::address_t& draw_legs = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4C 8B DC 55 53 56 57 41 57 49 8D AB 78 FB FF FF"),
		::protection::addresses::address_type::pattern,
		"client.dll:4C 8B DC 55 53 56 57 41 57 49 8D AB 78 FB FF FF");

	const ::protection::addresses::address_t& draw_overhead = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40534883EC??488BD983FA??75??"),
		::protection::addresses::address_type::pattern,
		"client.dll:40534883EC??488BD983FA??75??");

	const ::protection::addresses::address_t& draw_scene_object = ADDRESS_IMPL(
		::protection::addresses::hash("scenesystem.dll:488D05*????????488907488B7C2448+8~"),
		::protection::addresses::address_type::pattern,
		"scenesystem.dll:488D05*????????488907488B7C2448+8~");

	const ::protection::addresses::address_t& draw_scene_object_array = ADDRESS_IMPL(
		::protection::addresses::hash("scenesystem.dll:488BC4488950??488948??555356574154415541564157488DA8????????4881EC????????0F2970??"),
		::protection::addresses::address_type::pattern,
		"scenesystem.dll:488BC4488950??488948??555356574154415541564157488DA8????????4881EC????????0F2970??");

	const ::protection::addresses::address_t& draw_skybox_array = ADDRESS_IMPL(
		::protection::addresses::hash("scenesystem.dll:4585C90F8E????????4C8BDC"),
		::protection::addresses::address_type::pattern,
		"scenesystem.dll:4585C90F8E????????4C8BDC");

	const ::protection::addresses::address_t& dynamic_light_alloc = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488BD94533C0488B0D????????BA01000000>E8????????8B0B"),
		::protection::addresses::address_type::pattern,
		"client.dll:488BD94533C0488B0D????????BA01000000>E8????????8B0B");

	const ::protection::addresses::address_t& dynamic_light_manager = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????4885C97408488BD7E8????????E8????????BAFFFFFFFF"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????4885C97408488BD7E8????????E8????????BAFFFFFFFF");

	const ::protection::addresses::address_t& dynamic_light_time = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40534883EC20488BD985D2741A488B05????????F30F104830"),
		::protection::addresses::address_type::pattern,
		"client.dll:40534883EC20488BD985D2741A488B05????????F30F104830");

	const ::protection::addresses::address_t& engine_client_cmd = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 41 56 41 57 48 81 EC 70"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 41 56 41 57 48 81 EC 70");

	const ::protection::addresses::address_t& entity_list = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????8BFBC1EB0E"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????8BFBC1EB0E");

	const ::protection::addresses::address_t& filesystem_close = ADDRESS_IMPL(
		::protection::addresses::hash("filesystem_stdio.dll:488D8F20FFFFFF8BD5>E8????????FFD34C8D5C2460"),
		::protection::addresses::address_type::pattern,
		"filesystem_stdio.dll:488D8F20FFFFFF8BD5>E8????????FFD34C8D5C2460");

	const ::protection::addresses::address_t& find_hud_element = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40 53 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B D9 48 85 C0 74 79 48 89 5C"),
		::protection::addresses::address_type::pattern,
		"client.dll:40 53 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B D9 48 85 C0 74 79 48 89 5C");

	const ::protection::addresses::address_t& frame_input_ring_base = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:488D05*????????0F1004C8"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:488D05*????????0F1004C8");

	const ::protection::addresses::address_t& frame_input_ring_idx = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:486315*????????83FA0A7D61"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:486315*????????83FA0A7D61");

	const ::protection::addresses::address_t& frame_stage_notify = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C241848896C2420574883EC40488BF9"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C241848896C2420574883EC40488BF9");

	const ::protection::addresses::address_t& game_entity_system = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????EB028BC6"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????EB028BC6");

	const ::protection::addresses::address_t& game_event_get_controller = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488D05*????????4D8BF8488901+80~"),
		::protection::addresses::address_type::pattern,
		"client.dll:488D05*????????4D8BF8488901+80~");

	const ::protection::addresses::address_t& game_event_get_float = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????0F28D8895C2420"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????0F28D8895C2420");

	const ::protection::addresses::address_t& game_event_get_int = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????3D00800000"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????3D00800000");

	const ::protection::addresses::address_t& game_event_get_pawn = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488D05*????????4D8BF8488901+88~"),
		::protection::addresses::address_type::pattern,
		"client.dll:488D05*????????4D8BF8488901+88~");

	const ::protection::addresses::address_t& game_event_get_string = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????85DB0F9FC3"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????85DB0F9FC3");

	const ::protection::addresses::address_t& game_event_manager = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????488B01FF50??FFC3~"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????488B01FF50??FFC3~");

	const ::protection::addresses::address_t& game_rules = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????4C897010"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????4C897010");

	const ::protection::addresses::address_t& game_scene_node_set_mesh_group = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????8B852C850100"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????8B852C850100");

	const ::protection::addresses::address_t& game_scene_node_set_skeleton = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????4084ED7417"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????4084ED7417");

	const ::protection::addresses::address_t& game_trace_manager = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 8B 0D * ? ? ? ? 48 8B D0 C7 44 24 ? 04 00 00 00 48 C7 44 24 ? 01 30 1C 00~"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 8B 0D * ? ? ? ? 48 8B D0 C7 44 24 ? 04 00 00 00 48 C7 44 24 ? 01 30 1C 00~");

	const ::protection::addresses::address_t& generate_primitives = ADDRESS_IMPL(
		::protection::addresses::hash("scenesystem.dll:488D05*????????488907488B7C2448+20~"),
		::protection::addresses::address_type::pattern,
		"scenesystem.dll:488D05*????????488907488B7C2448+20~");

	const ::protection::addresses::address_t& get_aim_punch = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488BC4488958104889681848897020574883EC70488BEA410FB6F0488D5008488BF9"),
		::protection::addresses::address_type::pattern,
		"client.dll:488BC4488958104889681848897020574883EC70488BEA410FB6F0488D5008488BF9");

	const ::protection::addresses::address_t& get_shot_aim_punch = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4C8BDC49895B0849896B1049897318574883EC70488BD944884C24384D8943B8"),
		::protection::addresses::address_type::pattern,
		"client.dll:4C8BDC49895B0849896B1049897318574883EC70488BD944884C24384D8943B8");

	const ::protection::addresses::address_t& get_bone_index = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:448B42??488B12E9"),
		::protection::addresses::address_type::pattern,
		"client.dll:448B42??488B12E9");

	const ::protection::addresses::address_t& get_glow_color = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????F30F10BE????????488BCF"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????F30F10BE????????488BCF");

	const ::protection::addresses::address_t& get_inaccuracy = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??5556574881EC????????440F298424"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??5556574881EC????????440F298424");

	const ::protection::addresses::address_t& get_interp_amount = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????418B9668030000"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????418B9668030000");

	const ::protection::addresses::address_t& get_interpolated_shoot_position = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40555641564881EC20010000"),
		::protection::addresses::address_type::pattern,
		"client.dll:40555641564881EC20010000");

	const ::protection::addresses::address_t& get_spread = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:486391001A0000488B818803000085D278104883FA02730AF30F10849050070000C3F30F108050070000C3"),
		::protection::addresses::address_type::pattern,
		"client.dll:486391001A0000488B818803000085D278104883FA02730AF30F10849050070000C3F30F108050070000C3");

	const ::protection::addresses::address_t& get_net_channel = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:4C8B05????????4D85C07410"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:4C8B05????????4D85C07410");

	const ::protection::addresses::address_t& get_tick_view_angles = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C2408574881ECF0000000F30F100A488D8C2410010000418BD8488BFAE8????????F30F104F04"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C2408574881ECF0000000F30F100A488D8C2410010000418BD8488BFAE8????????F30F104F04");

	const ::protection::addresses::address_t& get_transforms_for_hitbox_list = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??555657415441554881EC????????4963304D8BE0488BEA488BD985F6"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??555657415441554881EC????????4963304D8BE0488BEA488BD985F6");

	const ::protection::addresses::address_t& get_usercmd = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40 53 48 83 EC 20 8B DA E8 ? ? ? ? 4C 8B C0"),
		::protection::addresses::address_type::pattern,
		"client.dll:40 53 48 83 EC 20 8B DA E8 ? ? ? ? 4C 8B C0");

	const ::protection::addresses::address_t& get_usercmd_base = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4883EC28>E8????????8B8010590000"),
		::protection::addresses::address_type::pattern,
		"client.dll:4883EC28>E8????????8B8010590000");

	const ::protection::addresses::address_t& get_view_angles = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4C 8B C1 85 D2 74 08 48 8D 05 ? ? ? ? C3 8B"),
		::protection::addresses::address_type::pattern,
		"client.dll:4C 8B C1 85 D2 74 08 48 8D 05 ? ? ? ? C3 8B");

	const ::protection::addresses::address_t& get_world_group_handle = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????418B5F10"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????418B5F10");

	const ::protection::addresses::address_t& get_world_group_id = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 8B 41 30 48 85 C0 74 ? 48 8B 40 10"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 8B 41 30 48 85 C0 74 ? 48 8B 40 10");

	const ::protection::addresses::address_t& global_vars = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B05*????????448B4044"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B05*????????448B4044");

	const ::protection::addresses::address_t& handle_view_angles = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:FFFFFFFF488D05*????????48890D????????+40~"),
		::protection::addresses::address_type::pattern,
		"client.dll:FFFFFFFF488D05*????????48890D????????+40~");

	const ::protection::addresses::address_t& history_field_alloc = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????488BD0488D4E28"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????488BD0488D4E28");

	const ::protection::addresses::address_t& hud = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B05*????????4885C07471"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B05*????????4885C07471");

	const ::protection::addresses::address_t& hud_death_notice_clear = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:85C07509488D4EE0>E8????????488B5C2440"),
		::protection::addresses::address_type::pattern,
		"client.dll:85C07509488D4EE0>E8????????488B5C2440");

	const ::protection::addresses::address_t& hud_weapon_selection_update = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:498BE35FC3488BCB>E8????????488BCBE8????????"),
		::protection::addresses::address_type::pattern,
		"client.dll:498BE35FC3488BCB>E8????????488BCBE8????????");

	const ::protection::addresses::address_t& anim_graph_create_bindings = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40574883EC504883794000488BF90F8561010000488B49304885C90F845401000080BF90000000000F8507010000"),
		::protection::addresses::address_type::pattern,
		"client.dll:40574883EC504883794000488BF90F8561010000488B49304885C90F845401000080BF90000000000F8507010000");

	const ::protection::addresses::address_t& init_particle_path_buffer = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??574883EC??8B41??488D79"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??574883EC??8B41??488D79");

	const ::protection::addresses::address_t& init_particle_path_buffer_alt = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??574883EC??8B41??488D79"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??574883EC??8B41??488D79");

	const ::protection::addresses::address_t& is_glowing = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:0000488BEA488BF9>E8????????4533F684C0"),
		::protection::addresses::address_type::pattern,
		"client.dll:0000488BEA488BF9>E8????????4533F684C0");

	const ::protection::addresses::address_t& item_system = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4883EC28488B05????????4885C00F8581"),
		::protection::addresses::address_type::pattern,
		"client.dll:4883EC28488B05????????4885C00F8581");

	const ::protection::addresses::address_t& kv3_alloc = ADDRESS_IMPL(
		::protection::addresses::hash("tier0.dll:40534883EC3080FA060FB6C241B916"),
		::protection::addresses::address_type::pattern,
		"tier0.dll:40534883EC3080FA060FB6C241B916");

	const ::protection::addresses::address_t& kv3_destroy = ADDRESS_IMPL(
		::protection::addresses::hash("tier0.dll:405741574883EC384C8B01448BFA498BC0488BF948C1E802"),
		::protection::addresses::address_type::pattern,
		"tier0.dll:405741574883EC384C8B01448BFA498BC0488BF948C1E802");

	const ::protection::addresses::address_t& kv3_load = ADDRESS_IMPL(
		::protection::addresses::hash("tier0.dll:44242848897C2420>E8????????0FB6D88B4C2444"),
		::protection::addresses::address_type::pattern,
		"tier0.dll:44242848897C2420>E8????????0FB6D88B4C2444");

	const ::protection::addresses::address_t& level_initialization = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488D05*????????C6411000+B8~"),
		::protection::addresses::address_type::pattern,
		"client.dll:488D05*????????C6411000+B8~");

	const ::protection::addresses::address_t& level_shutdown = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4883EC??488B0D????????488D15????????4533C94533C0488B01FF50304885C074??488B0D????????488BD04C8B0141FF50404883C4??"),
		::protection::addresses::address_type::pattern,
		"client.dll:4883EC??488B0D????????488D15????????4533C94533C0488B01FF50304885C074??488B0D????????488BD04C8B0141FF50404883C4??");

	const ::protection::addresses::address_t& light_data_queue = ADDRESS_IMPL(
		::protection::addresses::hash("scenesystem.dll:488B05*????????48C1E104+8"),
		::protection::addresses::address_type::pattern,
		"scenesystem.dll:488B05*????????48C1E104+8");

	const ::protection::addresses::address_t& light_scene_object = ADDRESS_IMPL(
		::protection::addresses::hash("scenesystem.dll:>E8????????440F285C2460"),
		::protection::addresses::address_type::pattern,
		"scenesystem.dll:>E8????????440F285C2460");

	const ::protection::addresses::address_t& local_player_controller = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48391D*????????7504B001"),
		::protection::addresses::address_type::pattern,
		"client.dll:48391D*????????7504B001");

	const ::protection::addresses::address_t& log_internal = ADDRESS_IMPL(
		::protection::addresses::hash("tier0.dll:>E8????????448B55B3"),
		::protection::addresses::address_type::pattern,
		"tier0.dll:>E8????????448B55B3");

	const ::protection::addresses::address_t& material_create = ADDRESS_IMPL(
		::protection::addresses::hash("materialsystem2.dll:48895C24??48896C24??48897424??48897C24??41564881EC????????488B05????????488BF2"),
		::protection::addresses::address_type::pattern,
		"materialsystem2.dll:48895C24??48896C24??48897424??48897C24??41564881EC????????488B05????????488BF2");

	const ::protection::addresses::address_t& material_manager = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????80A5E7000000EF"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????80A5E7000000EF");

	const ::protection::addresses::address_t& override_view = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:A8000000488D05*????????4C89742420+78~"),
		::protection::addresses::address_type::pattern,
		"client.dll:A8000000488D05*????????4C89742420+78~");

	const ::protection::addresses::address_t& on_client_frame_simulate = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:488BC4554154415541564157488D68B84881EC20010000488970D04533F6"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:488BC4554154415541564157488D68B84881EC20010000488970D04533F6");
	const ::protection::addresses::address_t& on_client_frame_send_service = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:488B0D*????????8986CC000000488B01FF9070050000440FB67F30"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:488B0D*????????8986CC000000488B01FF9070050000440FB67F30");
	const ::protection::addresses::address_t& parse_report_hit = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24184889742420574883EC20488BF1488BFA"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24184889742420574883EC20488BF1488BFA");

	const ::protection::addresses::address_t& particle_create_effect = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4C8BDC534881EC90000000F20F1005"),
		::protection::addresses::address_type::pattern,
		"client.dll:4C8BDC534881EC90000000F20F1005");

	const ::protection::addresses::address_t& particle_destroy_effect = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:83FAFF0F84????????4154"),
		::protection::addresses::address_type::pattern,
		"client.dll:83FAFF0F84????????4154");

	const ::protection::addresses::address_t& particle_manager = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B35*????????44896C24??"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B35*????????44896C24??");

	const ::protection::addresses::address_t& particle_set_control_point = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4883EC58F3410F105104F3410F1009F3410F105908"),
		::protection::addresses::address_type::pattern,
		"client.dll:4883EC58F3410F105104F3410F1009F3410F105908");

	const ::protection::addresses::address_t& particle_set_entity_binding = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4154415541574881EC900000004D8BF9"),
		::protection::addresses::address_type::pattern,
		"client.dll:4154415541574881EC900000004D8BF9");

	const ::protection::addresses::address_t& particle_set_transform = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??48896C24??48897424??574883EC40488BF9498BE9"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??48896C24??48897424??574883EC40488BF9498BE9");

	const ::protection::addresses::address_t& planted_c4 = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B1D*????????488BD34C8B81"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B1D*????????488BD34C8B81");

	const ::protection::addresses::address_t& post_network_data_received = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 10 48 89 4C 24 08 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 00 FD FF"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 10 48 89 4C 24 08 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 00 FD FF");

	const ::protection::addresses::address_t& prediction_finish_move = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488BC4535641554881ECE0000000440F2940A84533ED498BF0"),
		::protection::addresses::address_type::pattern,
		"client.dll:488BC4535641554881ECE0000000440F2940A84533ED498BF0");

	const ::protection::addresses::address_t& prediction_player = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B4738488D0D????????488905*????????488D15????????83FD03"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B4738488D0D????????488905*????????488D15????????83FD03");

	const ::protection::addresses::address_t& prediction_process_movement = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 8B C4 53 56 48 81 EC ? ? ? ? 0F 29 78 A8"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 8B C4 53 56 48 81 EC ? ? ? ? 0F 29 78 A8");

	const ::protection::addresses::address_t& prediction_reset_pawn = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B114885D274??806A????75??488B05????????8B4044894218"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B114885D274??806A????75??488B05????????8B4044894218");

	const ::protection::addresses::address_t& prediction_seed = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:8B3D*????????488B03488BCB"),
		::protection::addresses::address_type::pattern,
		"client.dll:8B3D*????????488B03488BCB");

	const ::protection::addresses::address_t& prediction_set_pawn = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??574883EC2048C70100000000488BFA488BD94885D274??488B02"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??574883EC2048C70100000000488BFA488BD94885D274??488B02");

	const ::protection::addresses::address_t& prediction_set_state = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:8B81????????84D274??FFC08981????????C383E8018981????????75??80B9"),
		::protection::addresses::address_type::pattern,
		"client.dll:8B81????????84D274??FFC08981????????C383E8018981????????75??80B9");

	const ::protection::addresses::address_t& prediction_setup_move = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:80 21 FE 44 08 09 41 0F B6 C1 83 F0 01 44 89 81"),
		::protection::addresses::address_type::pattern,
		"client.dll:80 21 FE 44 08 09 41 0F B6 C1 83 F0 01 44 89 81");

	const ::protection::addresses::address_t& prediction_state = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????33D28B5B38"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????33D28B5B38");

	const ::protection::addresses::address_t& prepare_scene_material = ADDRESS_IMPL(
		::protection::addresses::hash("materialsystem2.dll:48895C24084889742410574883EC30488B5920"),
		::protection::addresses::address_type::pattern,
		"materialsystem2.dll:48895C24084889742410574883EC30488B5920");

	const ::protection::addresses::address_t& process_input_event = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:CCCC48895C2408574883EC20C6410800488D05*????????488901488BD9+20~"),
		::protection::addresses::address_type::pattern,
		"client.dll:CCCC48895C2408574883EC20C6410800488D05*????????488901488BD9+20~");

	const ::protection::addresses::address_t& read_frame_input = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????4D8BC58BD3"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????4D8BC58BD3");

	const ::protection::addresses::address_t& remove_entity = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 74 24 10 57 48 83 EC 20 41 B9 FF 7F 00 00 41 8B C0 41 23 C1 48 8B F2 41 83 F8 FF 48 8B F9 44 0F 45 C8 41 81 F9 00 40 00 00 73 08 FF 89 20"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 74 24 10 57 48 83 EC 20 41 B9 FF 7F 00 00 41 8B C0 41 23 C1 48 8B F2 41 83 F8 FF 48 8B F9 44 0F 45 C8 41 81 F9 00 40 00 00 73 08 FF 89 20");

	const ::protection::addresses::address_t& render_crosshair = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 08 57 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 85"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 08 57 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 85");

	const ::protection::addresses::address_t& render_decals = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:44 88 4C 24 20 55 53 41 54 41 55 48 8D 6C 24 C1"),
		::protection::addresses::address_type::pattern,
		"client.dll:44 88 4C 24 20 55 53 41 54 41 55 48 8D 6C 24 C1");

	const ::protection::addresses::address_t& render_game_system_storage = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B0D*????????418BD6E8????????418B5F"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B0D*????????418BD6E8????????418B5F");

	const ::protection::addresses::address_t& render_scope = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488BC453574883EC68488BFA"),
		::protection::addresses::address_type::pattern,
		"client.dll:488BC453574883EC68488BFA");

	const ::protection::addresses::address_t& render_smoke = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:5C24284889442420>E8????????488B5C2460"),
		::protection::addresses::address_type::pattern,
		"client.dll:5C24284889442420>E8????????488B5C2460");

	const ::protection::addresses::address_t& render_view = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4C 8B DC 53 55 57 41 55 48 81 EC D8 00 00 00 48"),
		::protection::addresses::address_type::pattern,
		"client.dll:4C 8B DC 53 55 57 41 55 48 81 EC D8 00 00 00 48");

	const ::protection::addresses::address_t& resource_system_load = ADDRESS_IMPL(
		::protection::addresses::hash("resourcesystem.dll:48895C24??48896C24??48897424??574883EC??488B01"),
		::protection::addresses::address_type::pattern,
		"resourcesystem.dll:48895C24??48896C24??48897424??574883EC??488B01");

	const ::protection::addresses::address_t& resource_system_precache = ADDRESS_IMPL(
		::protection::addresses::hash("resourcesystem.dll:405355574881EC80000000"),
		::protection::addresses::address_type::pattern,
		"resourcesystem.dll:405355574881EC80000000");

	const ::protection::addresses::address_t& serialize_move_crc = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??5556574883EC30498BC0488BFA488BF1488B09F6C103"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??5556574883EC30498BC0488BFA488BF1488B09F6C103");

	const ::protection::addresses::address_t& send_tick_packet = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:405541564883EC6880B900010000008BEA4C8BF1"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:405541564883EC6880B900010000008BEA4C8BF1");

	const ::protection::addresses::address_t& service_read = ADDRESS_IMPL(
		::protection::addresses::hash("filesystem_stdio.dll:00488907488D05*????????488987E0000000~"),
		::protection::addresses::address_type::pattern,
		"filesystem_stdio.dll:00488907488D05*????????488987E0000000~");

	const ::protection::addresses::address_t& set_info = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:40554157488D6C24??4881EC????????4533FF"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:40554157488D6C24??4881EC????????4533FF");

	const ::protection::addresses::address_t& set_player_model = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488D15????????488BCB>E8????????488BD7488BCB"),
		::protection::addresses::address_type::pattern,
		"client.dll:488D15????????488BCB>E8????????488BD7488BCB");

	const ::protection::addresses::address_t& set_postprocess_vec = ADDRESS_IMPL(
		::protection::addresses::hash("engine2.dll:>E8????????440F289424"),
		::protection::addresses::address_type::pattern,
		"engine2.dll:>E8????????440F289424");

	const ::protection::addresses::address_t& set_shader_param = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8 ?? ?? ?? ?? F3 0F 10 47 6C 4C 8D 44 24 30 0F C6 C0 00 BA 00 51 8B B0"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8 ?? ?? ?? ?? F3 0F 10 47 6C 4C 8D 44 24 30 0F C6 C0 00 BA 00 51 8B B0");

	const ::protection::addresses::address_t& set_shader_param_i = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 66 0F 6E CA 41 8B F0"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 66 0F 6E CA 41 8B F0");

	const ::protection::addresses::address_t& set_view_angles = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:85 D2 75 ? 48 63 81"),
		::protection::addresses::address_type::pattern,
		"client.dll:85 D2 75 ? 48 63 81");

	const ::protection::addresses::address_t& set_voice_data = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????4C39B5C8140000"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????4C39B5C8140000");

	const ::protection::addresses::address_t& simulation_player = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4C3905*????????400F94C5"),
		::protection::addresses::address_type::pattern,
		"client.dll:4C3905*????????400F94C5");

	const ::protection::addresses::address_t& sort_primitives = ADDRESS_IMPL(
		::protection::addresses::hash("scenesystem.dll:4585C90F84????????5556574883EC30"),
		::protection::addresses::address_type::pattern,
		"scenesystem.dll:4585C90F84????????5556574883EC30");

	const ::protection::addresses::address_t& setup_fog = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??48896C24??48897424??48894C24??5741544155415641574883EC20486302"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??48896C24??48897424??48894C24??5741544155415641574883EC20486302");

	const ::protection::addresses::address_t& play_sound = ADDRESS_IMPL(
		::protection::addresses::hash("soundsystem.dll:4C8BDC55415541564157"),
		::protection::addresses::address_type::pattern,
		"soundsystem.dll:4C8BDC55415541564157");

	const ::protection::addresses::address_t& string_copy = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????0F104588"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????0F104588");

	const ::protection::addresses::address_t& subtick_move_alloc = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488B54CA088D4101894708EB16488B0F>E8????????488BD0488BCF"),
		::protection::addresses::address_type::pattern,
		"client.dll:488B54CA088D4101894708EB16488B0F>E8????????488BD0488BCF");

	const ::protection::addresses::address_t& trace_bullet = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40 53 57 41 56 48 83 EC 50 8B 84 24 90 00 00 00"),
		::protection::addresses::address_type::pattern,
		"client.dll:40 53 57 41 56 48 83 EC 50 8B 84 24 90 00 00 00");

	const ::protection::addresses::address_t& trace_bullet_data_init = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? ? ? ? ? 4D 8D 71"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? ? ? ? ? 4D 8D 71");

	const ::protection::addresses::address_t& trace_bullet_update = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B E9 0F 29 74 24 ? 48 8B CA 49 8B F9"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B E9 0F 29 74 24 ? 48 8B CA 49 8B F9");

	const ::protection::addresses::address_t& trace_bullet_free = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 79 ? 33 F6 C7 47"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 79 ? 33 F6 C7 47");

	const ::protection::addresses::address_t& trace_filter_init = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24");

	const ::protection::addresses::address_t& trace_filter_set_collision = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF C7 41 ?"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF C7 41 ?");

	const ::protection::addresses::address_t& trace_hull = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 74 24 18 55 57 41 54 41 55 41 56 48 8D AC"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 74 24 18 55 57 41 54 41 55 41 56 48 8D AC");

	const ::protection::addresses::address_t& trace_ray = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 54 24 10 48 89 4C 24 08 55 53 56 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? B8"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 54 24 10 48 89 4C 24 08 55 53 56 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? B8");

	const ::protection::addresses::address_t& trace_ray_entity = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4C 8B DC 49 89 5B 08 49 89 6B 10 49 89 73 18 57 48 81 EC ? ? ? ? 33 C0 0F 57 C0 66 0F 7F 44 24 ? 49 8B F8"),
		::protection::addresses::address_type::pattern,
		"client.dll:4C 8B DC 49 89 5B 08 49 89 6B 10 49 89 73 18 57 48 81 EC ? ? ? ? 33 C0 0F 57 C0 66 0F 7F 44 24 ? 49 8B F8");

	const ::protection::addresses::address_t& update_fov_sensitivity = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 48 8B B9 28 13"),
		::protection::addresses::address_type::pattern,
		"client.dll:48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 48 8B B9 28 13");

	const ::protection::addresses::address_t& utl_vector_push = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????4C8BD0458B4A10"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????4C8BD0458B4A10");

	const ::protection::addresses::address_t& view_matrix = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488D0D*????????48C1E006"),
		::protection::addresses::address_type::pattern,
		"client.dll:488D0D*????????48C1E006");

	const ::protection::addresses::address_t& viewmodel_update_mesh = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????498D8D??????????????488D5424"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????498D8D??????????????488D5424");

	const ::protection::addresses::address_t& weapon_calculate_spread = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:28F3440F11442420>E8????????488D85B0000000"),
		::protection::addresses::address_type::pattern,
		"client.dll:28F3440F11442420>E8????????488D85B0000000");

	const ::protection::addresses::address_t& entity_get_index = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:4883EC084C8B0D????????4C8BDA488B49104983C1104885C9750EC702FFFFFFFF488BC24883C408C3"),
		::protection::addresses::address_type::pattern,
		"client.dll:4883EC084C8B0D????????4C8BDA488B49104983C1104885C9750EC702FFFFFFFF488BC24883C408C3");

	const ::protection::addresses::address_t& weapon_get_model_path = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C2410564883EC20488B1D????????"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C2410564883EC20488B1D????????");

	const ::protection::addresses::address_t& weapon_get_recoil_offset = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????488D44243C"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????488D44243C");

	const ::protection::addresses::address_t& weapon_get_viewmodel = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40534883EC20488BD9E8????????4883BB8803000000"),
		::protection::addresses::address_type::pattern,
		"client.dll:40534883EC20488BD9E8????????4883BB8803000000");

	const ::protection::addresses::address_t& weapon_recoil_data = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:488D0D*????????488D8424????????41B801000000"),
		::protection::addresses::address_type::pattern,
		"client.dll:488D0D*????????488D8424????????41B801000000");

	const ::protection::addresses::address_t& weapon_set_mesh_group_mask = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??48897424??574883EC??488D99????????488B71"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??48897424??574883EC??488D99????????488B71");

	const ::protection::addresses::address_t& weapon_update_accuracy = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:405741564883EC68488BF9E8????????4C8BF04885C0"),
		::protection::addresses::address_type::pattern,
		"client.dll:405741564883EC68488BF9E8????????4C8BF04885C0");

	const ::protection::addresses::address_t& weapon_update_composite_material = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C241048896C2418488974242057415641574883EC20440FB6F2488BF9"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C241048896C2418488974242057415641574883EC20440FB6F2488BF9");

	const ::protection::addresses::address_t& weapon_update_mesh = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:>E8????????498D8C2408060000"),
		::protection::addresses::address_type::pattern,
		"client.dll:>E8????????498D8C2408060000");

	const ::protection::addresses::address_t& weapon_update_skin = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40 55 53 41 57 48 8D AC 24 00 FE FF FF 48 81 EC"),
		::protection::addresses::address_type::pattern,
		"client.dll:40 55 53 41 57 48 8D AC 24 00 FE FF FF 48 81 EC");

	const ::protection::addresses::address_t& econ_item_view_set_attribute = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40534883EC20488BD94881C108020000"),
		::protection::addresses::address_type::pattern,
		"client.dll:40534883EC20488BD94881C108020000");

	const ::protection::addresses::address_t& econ_item_view_remove_attribute = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:40534883EC20486381????????440FB7CA"),
		::protection::addresses::address_type::pattern,
		"client.dll:40534883EC20486381????????440FB7CA");

	const ::protection::addresses::address_t& econ_item_view_invalidate_description = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:48895C24??48897424??574883EC20488DB9????????488BF1"),
		::protection::addresses::address_type::pattern,
		"client.dll:48895C24??48897424??574883EC20488DB9????????488BF1");

	const ::protection::addresses::address_t& set_bodygroup = ADDRESS_IMPL(
		::protection::addresses::hash("client.dll:85D20F88????????555657"),
		::protection::addresses::address_type::pattern,
		"client.dll:85D20F88????????555657");

} // namespace patterns
